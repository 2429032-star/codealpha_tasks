#include <stdio.h>

struct Account {
    int accNo;
    char name[50];
    float balance;
};

void createAccount() {
    FILE *fp;
    struct Account a;

    fp = fopen("bank.dat", "ab");

    printf("Enter Account Number: ");
    scanf("%d", &a.accNo);

    printf("Enter Account Holder Name: ");
    scanf("%s", a.name);

    printf("Enter Initial Balance: ");
    scanf("%f", &a.balance);

    fwrite(&a, sizeof(a), 1, fp);
    fclose(fp);

    printf("Account created successfully.\n");
}

void deposit() {
    FILE *fp;
    struct Account a;
    int accNo, found = 0;
    float amount;

    fp = fopen("bank.dat", "rb+");

    printf("Enter Account Number: ");
    scanf("%d", &accNo);

    while(fread(&a, sizeof(a), 1, fp)) {
        if(a.accNo == accNo) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);

            a.balance += amount;

            fseek(fp, -sizeof(a), SEEK_CUR);
            fwrite(&a, sizeof(a), 1, fp);

            printf("Amount deposited successfully.\n");
            found = 1;
            break;
        }
    }

    if(!found)
        printf("Account not found.\n");

    fclose(fp);
}

void withdraw() {
    FILE *fp;
    struct Account a;
    int accNo, found = 0;
    float amount;

    fp = fopen("bank.dat", "rb+");

    printf("Enter Account Number: ");
    scanf("%d", &accNo);

    while(fread(&a, sizeof(a), 1, fp)) {
        if(a.accNo == accNo) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);

            if(amount <= a.balance) {
                a.balance -= amount;

                fseek(fp, -sizeof(a), SEEK_CUR);
                fwrite(&a, sizeof(a), 1, fp);

                printf("Amount withdrawn successfully.\n");
            } else {
                printf("Insufficient balance.\n");
            }

            found = 1;
            break;
        }
    }

    if(!found)
        printf("Account not found.\n");

    fclose(fp);
}

void balanceEnquiry() {
    FILE *fp;
    struct Account a;
    int accNo, found = 0;

    fp = fopen("bank.dat", "rb");

    printf("Enter Account Number: ");
    scanf("%d", &accNo);

    while(fread(&a, sizeof(a), 1, fp)) {
        if(a.accNo == accNo) {
            printf("Account Holder: %s\n", a.name);
            printf("Balance: %.2f\n", a.balance);
            found = 1;
            break;
        }
    }

    if(!found)
        printf("Account not found.\n");

    fclose(fp);
}

int main() {
    int choice;

    do {
        printf("\n--- Bank Account Management System ---");
        printf("\n1. Create Account");
        printf("\n2. Deposit");
        printf("\n3. Withdraw");
        printf("\n4. Balance Enquiry");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: balanceEnquiry(); break;
            case 5: printf("Thank you.\n"); break;
            default: printf("Invalid choice.\n");
        }

    } while(choice != 5);

    return 0;
}
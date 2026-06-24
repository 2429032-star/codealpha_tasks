#include <stdio.h>

void inputMatrix(int a[10][10], int r, int c) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

void displayMatrix(int a[10][10], int r, int c) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int a[10][10], int b[10][10], int r, int c) {
    int sum[10][10];

    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            sum[i][j] = a[i][j] + b[i][j];

    printf("Matrix Addition Result:\n");
    displayMatrix(sum, r, c);
}

void multiplyMatrix(int a[10][10], int b[10][10], int r1, int c1, int c2) {
    int mul[10][10];

    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++) {
            mul[i][j] = 0;
            for(int k = 0; k < c1; k++) {
                mul[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("Matrix Multiplication Result:\n");
    displayMatrix(mul, r1, c2);
}

void transposeMatrix(int a[10][10], int r, int c) {
    printf("Transpose Matrix:\n");

    for(int i = 0; i < c; i++) {
        for(int j = 0; j < r; j++) {
            printf("%d ", a[j][i]);
        }
        printf("\n");
    }
}

int main() {
    int a[10][10], b[10][10];
    int r1, c1, r2, c2, choice;

    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter Matrix A elements:\n");
    inputMatrix(a, r1, c1);

    printf("Enter rows and columns of Matrix B: ");
    scanf("%d %d", &r2, &c2);

    printf("Enter Matrix B elements:\n");
    inputMatrix(b, r2, c2);

    printf("\n1. Matrix Addition");
    printf("\n2. Matrix Multiplication");
    printf("\n3. Transpose of Matrix A");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            if(r1 == r2 && c1 == c2)
                addMatrix(a, b, r1, c1);
            else
                printf("Addition not possible.");
            break;

        case 2:
            if(c1 == r2)
                multiplyMatrix(a, b, r1, c1, c2);
            else
                printf("Multiplication not possible.");
            break;

        case 3:
            transposeMatrix(a, r1, c1);
            break;

        default:
            printf("Invalid choice.");
    }

    return 0;
}
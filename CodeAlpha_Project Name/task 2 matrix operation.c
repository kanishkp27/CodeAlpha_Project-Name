//Matrix Addition
//Matrix Multiplication
//Transpose using Uses functions (modular code) Uses 2D arrays
#include <stdio.h>
#define MAX 10

// Function for Matrix Addition
void addMatrix(int r, int c, int A[MAX][MAX], int B[MAX][MAX]) {
    int result[MAX][MAX];
    printf("\nAddition Result:\n");
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            result[i][j] = A[i][j] + B[i][j];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

// Function for Matrix Multiplication
void multiplyMatrix(int r1, int c1, int c2, int A[MAX][MAX], int B[MAX][MAX]) {
    int result[MAX][MAX] = {0};
    printf("\nMultiplication Result:\n");

    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++) {
            for(int k = 0; k < c1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

// Function for Transpose
void transposeMatrix(int r, int c, int A[MAX][MAX]) {
    printf("\nTranspose Matrix:\n");
    for(int j = 0; j < c; j++) {
        for(int i = 0; i < r; i++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX];
    int r1, c1, r2, c2, choice;

    // Input first matrix
    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter elements of Matrix A:\n");
    for(int i = 0; i < r1; i++)
        for(int j = 0; j < c1; j++)
            scanf("%d", &A[i][j]);

    // Input second matrix
    printf("Enter rows and columns of Matrix B: ");
    scanf("%d %d", &r2, &c2);

    printf("Enter elements of Matrix B:\n");
    for(int i = 0; i < r2; i++)
        for(int j = 0; j < c2; j++)
            scanf("%d", &B[i][j]);

    // Choose Operation user choice
    printf("\nChoose Operation:\n");
    printf("1. Addition\n2. Multiplication\n3. Transpose (Matrix A)\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            if(r1 == r2 && c1 == c2)
                addMatrix(r1, c1, A, B);
            else
                printf("Addition not possible!\n");
            break;

        case 2:
            if(c1 == r2)
                multiplyMatrix(r1, c1, c2, A, B);
            else
                printf("Multiplication not possible!\n");
            break;

        case 3:
            transposeMatrix(r1, c1, A);
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
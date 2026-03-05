#include <stdio.h>

/*
/  EECS 348 Lab 5: Isaiah Jenks
/  This program will implement basic matrix operations: addition, multiplication, and
/  transposition with the hardcoded matrices. Then it will print the resulting matrices.
*/

//////////////// jail for hardcoded constants /////////////////

#define SIZE 5

const int m1[SIZE][SIZE] = {
    { 1,  2,  3,  4,  5},
    { 6,  7,  8,  9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25}
};
const int m2[SIZE][SIZE] = {
    {25, 24, 23, 22, 21},
    {20, 19, 18, 17, 16},
    {15, 14, 13, 12, 11},
    {10,  9,  8,  7,  6},
    {5,   4,  3,  2,  1}
};
///////////////////////////////////////////////////////////////


int matrixRet[SIZE][SIZE]; // Needs global scope to be returned into main.

// This function should take two matrices as input and return a matrix containing their sum.
int* addMatrices(int input1[SIZE][SIZE], int input2[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) { // for all rows-of-input1 / rows-of-input2  0 to SIZE-1 (must be the same for matrix addition to be valid)
        for (int j = 0; j < SIZE; j++) { // for all columns-of-input1 / columns-of-input2  0 to SIZE-1 (must be the same for matrix addition to be valid)
            matrixRet[i][j] = input1[i][j] + input2[i][j];
        }
    }
    return &matrixRet[0][0]; // Return the address of the first element of the resulting matrix
}

// This function should take two matrices as input and return a matrix containing their product.
int* multiplyMatrices(int input1[SIZE][SIZE], int input2[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) { // for all rows of input1 0 to SIZE-1
        for (int j = 0; j < SIZE; j++) { // for all columns of input2 0 to SIZE-1
            matrixRet[i][j] = 0;
            for (int k = 0; k < SIZE; k++) { // for all columns-of-input1 / rows-of-input2 0 to SIZE-1 (must be the same for matrix multiplication to be valid)
                matrixRet[i][j] += input1[i][k] * input2[k][j];
            }
        }
    }
    return &matrixRet[0][0]; // Return the address of the first element of the resulting matrix
}

// This function should take a matrix as input and return a matrix containing its transpose.
int* transposeMatrix(int input[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) { // for all rows 0 to SIZE-1
        for (int j = 0; j < SIZE; j++) { // for all columns 0 to SIZE-1
            matrixRet[i][j] = input[j][i];
        }
    }
    return &matrixRet[0][0]; // Return the address of the first element of the resulting matrix
}

// This function should take a matrix as input and print it in a user-friendly format.
void printMatrix(int input[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        printf("[ ");
        for (int j = 0; j < SIZE; j++) {
            printf("%4d ", input[i][j]);
        }
        printf("]\n");
    }
}

int main() {

    printf("Matrix 1:\n");
    printMatrix(m1);
    printf("\nMatrix 2:\n");
    printMatrix(m2);

    printf("\nMatrix 1 + Matrix 2:\n");
    printMatrix(addMatrices(m1, m2));

    printf("\nMatrix 1 * Matrix 2:\n");
    printMatrix(multiplyMatrices(m1, m2));

    printf("\nTranspose of Matrix 1:\n");
    printMatrix(transposeMatrix(m1));

    return 0;
}
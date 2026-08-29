/*
Program: transpose matrix
Description: create a program that transposes a matrix in same memory space
Input: int size to indicate the matrix size between 2 and 10. int entries of the matrix elements
Output: print of the transposed matrix on the same memory space
Author: Cristopher Hernández
Date: 18.03.2026
*/

#include <stdio.h>

#define MAX_SIZE 10
#define MIN_SIZE 2


int get_data(char msj[], int minLim, int maxLim);
void fill_matrix(int matrix[][MAX_SIZE], int size);
void print_matrix(int matrix[][MAX_SIZE], int size);
void get_transposed(int matrix[][MAX_SIZE], int size);

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int size;

    size = get_data("Enter the size of the matrix (2-10): ", MIN_SIZE, MAX_SIZE);

    fill_matrix(matrix, size);

    printf("\nOriginal:\n");
    print_matrix(matrix, size);

    get_transposed(matrix, size);

    printf("\nTransposed:\n");
    print_matrix(matrix, size);

    return 0;
}

int get_data(char msj[], int minLim, int maxLim) {
    int numero;
    
    do{
        printf("%s", msj);
        scanf("%d", &numero);
    }while (numero < minLim || numero > maxLim);

    return numero;
}

void fill_matrix(int matrix[][MAX_SIZE], int size) {
    int i, j;

    for (i = 0; i < size; i = i + 1) {
        for (j = 0; j < size; j = j + 1) {
            printf("Enter element [%d][%d]: ", i, j);
            matrix[i][j] = get_data("", -10000, 10000);
        }
    }

    return;
}

void print_matrix(int matrix[][MAX_SIZE], int size) {
    int i, j;

    for (i = 0; i < size; i = i + 1) {
        for (j = 0; j < size; j = j + 1) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return;
}

void get_transposed(int matrix[][MAX_SIZE], int size) {
    int i, j;
    int temp;

    for (i = 0; i < size; i = i + 1) {
        for (j = i + 1; j < size; j = j + 1) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    return;
}
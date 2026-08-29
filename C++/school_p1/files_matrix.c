/*--------------------------------------------------
Program: transpuesta archivos
Description: write a program to retrieve a matrix from a file and calculates the transpose
Input: vector matrix
Output: transposed matrix
Author: Cristopher Hernandez
Date: 20.04.2026
--------------------------------------------------*/

// Libraries
#include <stdio.h>

#define N 15
#define NEGATIVE_LIMIT -99999.0
#define POSITIVE_LIMIT 99999.0

// Function prototypes
void get_number(const char msj[], int *number, int minLim, int maxLim);
void get_decimal_number(const char msj[], float *number, int minLim, int maxLim);
void get_vector(const char msj[], float vector[], int size);
void get_matrix(const char msj[], float matrix[][N], int size);
void save_matrix(float matrix[][N], int size);
void print_matrix(float matrix[][N], int size);
int read_matrix_file(float matrix[][N]);

// Main function
int main(void) {
    int n;
    float m[N][N]={0.0}, t[N][N]={0.0};
    int file_size;

    get_number("Enter the size of the matrix: ", &n, 2, N);
    get_matrix("Enter the matrix values:\n", m, n);
    save_matrix(m, n);
    print_matrix(m, n);
    file_size = read_matrix_file(t);
    print_matrix(t, file_size);

    return 0;
}

void get_number(const char msj[], int *number, int minLim, int maxLim){
    do{
        printf("%s", msj);
        scanf("%d",number);
    }while(*number<minLim || *number>maxLim);

    return;
}

void get_decimal_number(const char msj[], float *number, int minLim, int maxLim){
    do{
        printf("%s", msj);
        scanf("%f",number);

    }while(*number<minLim || *number>maxLim);

    return;
}

void get_vector(const char msj[], float vector[], int size){
    int i;
    float number;
    printf("%s", msj);

    for(i=0; i<size; i++){
    printf("\tLine value [%d]: ", i);
        get_decimal_number("",&number,NEGATIVE_LIMIT,POSITIVE_LIMIT);
        vector[i]=number;
    }

    return;
}

void get_matrix(const char msj[], float matrix[][N], int size){
    int i;
    printf("%s", msj);

    for(i=0; i<size; i++){
        printf("Enter the matrix line [%d]:\n", i);
        get_vector("",matrix[i],size);
    }

    return;
}

void save_matrix(float matrix[][N], int size){

    FILE *f;
    FILE *f2;
    int i,j;

    /*
    f=fopen("sample_matrix.bin","wb");
    if(f!=NULL){
        fwrite(&size, sizeof(int), 1, f);
        fwrite(matrix, sizeof(float), N*size, f);
    }else{
        printf("Could not open file");
    }
    fclose(f);*/

    f2=fopen("sample_matrix_d_by_d.bin","wb");
    if(f2!=NULL){
        fwrite(&size, sizeof(int), 1, f2);
        for(i=0; i<size; i++){
            for(j=0; j<size; j++){
                fwrite(&matrix[i][j], sizeof(float), 1, f2);
            }
        }
    }else{
        printf("Could not write file\n");
    }
    fclose(f2);

    return;
}

int read_matrix_file(float matrix[][N]){

    int size;
    FILE *f;
    FILE *f2;
    long tam;
    int i,j;

    /*
    f=fopen("sample_matrix.bin", "rb");
    if(f!=NULL){
        fseek(f, 0, SEEK_END); //vamos al final del archivo
        tam=ftell(f); //leemos el valor del dato para tamaño
        size=(tam-sizeof(int))/(N*sizeof(float));
        fseek(f, sizeof(int), SEEK_SET); //saltamos el encabezado
        fread(matrix, sizeof(float), N*size, f);
    }else{
        printf("Could not open file requested\n");
    }
    fclose(f);*/

    f2=fopen("sample_matrix_d_by_d.bin", "rb");
    if(f2!=NULL){
        fread(&size, sizeof(size), 1, f2);
        for(i=0; i<size; i++){
            for(j=0; j<size; j++){
                fread(&matrix[i][j], sizeof(float), 1, f2);
            }
        }
    }else{
        printf("Could not open file requested\n");
    }
    fclose(f2);

    return size;
}

void print_matrix(float matrix[][N], int size){
    int i,j;
    printf("Stored matrix:\n{\n");
    for(i=0; i<size; i++){
        for(j=0; j<size; j++){
            printf(" %f ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("}\n");

    return;
}
/*
Program: find smallest number in an array
Description: create a program that finds the smallest number in an array of unsigned integers
Input: unsigned integers until the user enters 0 (which is not stored in the array).
Output: print of the smallest number, its position in the array, and all the numbers entered
Author: Cristopher Hernández
Date: 16.04.2026
*/

#include <stdio.h>

#define TAM_MAX 99999

void capturar_entero(const char msj[], unsigned int *dato, unsigned int minimo, unsigned int maximo);
void llenar_arreglo(unsigned int arreglo[], unsigned int *cantidad);
void encontrar_minimo(unsigned int arreglo[], unsigned int *cantidad, unsigned int *minimo, unsigned int *posicion);
void imprimir_resultados(unsigned int arreglo[], unsigned int *cantidad, unsigned int minimo, unsigned int posicion);


int main(void){
    unsigned int arreglo[TAM_MAX], cantidad, minimo, posicion;
    cantidad = 0;

    llenar_arreglo(arreglo, &cantidad);

    encontrar_minimo(arreglo, &cantidad, &minimo, &posicion);
    imprimir_resultados(arreglo, &cantidad, minimo, posicion);

    return 0;
}

void capturar_entero(const char msj[], unsigned int *dato, unsigned int minimo, unsigned int maximo){
    do{
        printf("%s (rango %u - %u): ", msj, minimo, maximo);
        scanf("%u", dato);
    }while (*dato < minimo || *dato > maximo);
    
    return;
}

void llenar_arreglo(unsigned int arreglo[], unsigned int *cantidad){
    unsigned int valor = 1;
    *cantidad = 0;

    while(valor != 0 && *cantidad < TAM_MAX){
        capturar_entero("Ingrese un numero entero positivo (0 para terminar)", &valor, 0U, TAM_MAX);
        arreglo[*cantidad] = valor;
        (*cantidad)++;
    }

    if(valor == 0 && *cantidad > 0){
        (*cantidad)--;
    }

    return;
}

void encontrar_minimo(unsigned int arreglo[], unsigned int *cantidad, unsigned int *minimo, unsigned int *posicion){    
    if (*cantidad == 0){
        *minimo = 0;
        *posicion = 0;
    }else{
        unsigned int i;
        *minimo = arreglo[0];
        *posicion = 0;
        for (i = 1; i < *cantidad; i++){
            if(arreglo[i] < *minimo){
                *minimo = arreglo[i];
                *posicion = i;
            }
        }
    }

    return;
}

void imprimir_resultados(unsigned int arreglo[], unsigned int *cantidad, unsigned int minimo, unsigned int posicion){
    unsigned int i;

    printf("\nDatos capturados (%u elementos)\n{", *cantidad);

    for (i = 0; i < *cantidad; i++){
       printf(" %u ", arreglo[i]);
    }

    printf("}\nNumero mas pequeno: %u\n", minimo);
    printf("Posicion: %u\n", posicion + 1);

    return;
}
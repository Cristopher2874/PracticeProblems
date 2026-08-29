/*
Programa 11: números gemelos
Descripción: Programa que dice si dos números son gemelos, es decir, si los dígitos aparecen el mismo número de veces.
Entrada: int n1, int n2, números enteros positivos, asumiendo que están en base 3. deben estar entre 100 y 222
Salida: int gemelo si los números son gemelos o no
Autor: Cristopher Hernández
Fecha: 23.02.2026
*/

#include <stdio.h>
#include <math.h>

unsigned es_base3(unsigned n);
unsigned get_input(char msj[], unsigned maxLim, unsigned minLim);
unsigned gemelos(unsigned n1, unsigned n2);
void print_result(unsigned n1, unsigned n2, unsigned gemelos);

int main(){
    unsigned n1, n2, gem;

    n1 = get_input("Ingresar primer número positivo mayor a cero entre 100 y 222: ", 222,100);
    n2 = get_input("Ingresar segundo número positivo mayor a cero 100 y 222: ", 222,100);

    gem = gemelos(n1, n2);

    print_result(n1, n2, gem);
}

unsigned es_base3(unsigned n){
    unsigned base_3 = 1;

    while(n > 0 && base_3 == 1){
        if(n % 10 > 2){
            base_3 = 0;
        }
        n /= 10;
    }

    return base_3; 
}

unsigned get_input(char msj[], unsigned maxLim, unsigned minLim){
    unsigned n;

    do{
        printf("%s",msj);
        scanf("%u", &n);
    } while(n<minLim || n>maxLim || !es_base3(n));

    return n;
}

unsigned gemelos(unsigned n1, unsigned n2){
    int cuenta0s = 0, cuenta1s = 0, cuenta2s = 0;

    while(n1 > 0 || n2 > 0){

        if(n1 > 0){
            int d1 = n1 % 10;

            if(d1 == 0) cuenta0s++;
            else if(d1 == 1) cuenta1s++;
            else if(d1 == 2) cuenta2s++;

            n1 /= 10;
        }

        if(n2 > 0){
            int d2 = n2 % 10;

            if(d2 == 0) cuenta0s--;
            else if(d2 == 1) cuenta1s--;
            else if(d2 == 2) cuenta2s--;

            n2 /= 10;
        }
    }

    return (cuenta0s == 0 && cuenta1s == 0 && cuenta2s == 0);
}

void print_result(unsigned n1, unsigned n2, unsigned gemelos){
    if(!gemelos){
        printf("No ");
    }
    printf("son números gemelos");
    return;
}
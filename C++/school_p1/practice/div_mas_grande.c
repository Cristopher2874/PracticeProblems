/*
Programa 1: divisor más grande
Descripción: Hacer un programa que pida un número n positvo mayor a cero. El programa debe encontrar el divisor más grande y manejar el caso de números primos.
Entrada: int n número mayor que cero a verificar
Salida: int divisor número indicando el mayor divisor del número
Autor: Cristopher Hernández
Fecha: 23.02.2026
*/

#include <stdio.h>
#include <math.h>

unsigned get_input(char msj[], unsigned maxLim, unsigned minLim);
int get_max_div(unsigned n);
void print_result(unsigned n, int d);

int main(){
    unsigned n;
    int divisor;

    unsigned top_limit = pow(2.0, (sizeof(unsigned)*8))-1;

    n = get_input("Ingresar número positivo mayor a cero: ", top_limit,1);

    divisor = get_max_div(n);

    print_result(n,divisor);
}

unsigned get_input(char msj[], unsigned maxLim, unsigned minLim){
    unsigned n;

    do{
        printf("%s",msj);
        scanf("%u", &n);
    } while(n<minLim || n>maxLim);

    return n;
}

int get_max_div(unsigned n){
    int divisor = -1;
    unsigned i = 2;

    if(n == 1){
        divisor = 0;
    }else{
        while(divisor == -1 && i*i <=n){
            if(n%i == 0){
                divisor = n/i;
            }
            i++;
        }
    }

    return divisor;
}

void print_result(unsigned n, int d){
    if(d == -1){
        printf("%u es un número primo",n);
    }else if(d == 0){
        printf("1 es un número sin divisor propio, puede ser 1 si se considera la excepción");
    }else{
        printf("El mayor divisor entero de %u es: %d",n,d);
    }
    return;
}
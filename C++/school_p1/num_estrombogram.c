/*
Programa: números estrombogramáticos
Descripción: Crear un programa que verifique si un número es o no estrombogramático. Un número estrobogramático es aquel que se ve igual al girarlo 180°.
Dígitos válidos y sus equivalencias:0 = 0 1 = 1 8 = 8 6 = 9 9 = 6
Entrada: int n número a verificar
Salida: int resultado 1 si el número es estrobogramático, 0 si no lo es
Autor: Cristopher Hernandez
Date: 17.02.2026
*/

#include <stdio.h>

int leerDato(char msj[]);
int esEstrobogramatico(int n);
void imprimirResultado(int n, int resultado);

int main() {
    int numero;
    int resultado;

    numero = leerDato("Ingrese un numero natural positivo: ");
    resultado = esEstrobogramatico(numero);
    imprimirResultado(numero, resultado);

    return 0;
}

int leerDato(char msj[]) {
    int n;
    do{
        printf("%s", msj);
        scanf("%d", &n);
    }while (n < 0);
    return n;
}

int esEstrobogramatico(int n) {

    int original = n;
    int divisor = 1;
    int temp = n;

    //divisor de cada número
    //esto sirve para obtener el primer dígito del número
    // calculamos el divisor para obtener el primer dígito del número
    // por ejemplo, para 1234, el divisor sería 1000
    // para 808 sería 100
    while (temp >= 10) {
        temp /= 10;
        divisor *= 10;
    }
    
    while (n > 0) {

        int primero = n / divisor;   // primer dígito
        int ultimo = n % 10;         

        // verificar solo los dígitos válidos y sus equivalencias
        if ((primero == 0 && ultimo == 0) ||
            (primero == 1 && ultimo == 1) ||
            (primero == 8 && ultimo == 8) ||
            (primero == 6 && ultimo == 9) ||
            (primero == 9 && ultimo == 6)) {

            // Quitamos primer y último dígito
            n = (n % divisor) / 10;
            divisor /= 100;

        } else {
            return 0;  // No es estrobogramático
        }
    }

    return 1;
}

void imprimirResultado(int n, int resultado) {

    if (resultado)
        printf("El numero %d es estrobogramatico\n", n);
    else
        printf("El numero %d NO es estrobogramatico\n", n);
}
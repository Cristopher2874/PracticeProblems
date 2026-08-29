/*
Programa 2: interes de capital
Descripción: Hacer un programa que calcule el capital final de una inversión con interés compuesto de capital inicial y tasa anual
Entrada: double ci para retener el capital inicial, double t para el tiempo en años, double r el interés anual
Salida: double cf denotando el capital final por interés
Autor: Cristopher Hernández
Fecha: 23.02.2026
*/

#include <stdio.h>

double get_input(char msj[], double maxLim, double minLim);
double get_interest(double ci, double t, double r);
void print_result(double ci, double t, double r, double cf);

int main(){
    double ci, t, r, cf;

    double top_limit = 10e307;

    ci = get_input("Ingrese el capital inicial positivo distinto de 0: ", top_limit,0.0);
    t = get_input("Ingrese el tiempo de inversión en años, distinto de 0: ", top_limit,0.0);
    r = get_input("Ingrese la tasa de interés anual distinta de cero, en porcentaje (ej. 5, 10, 17): ", top_limit,0.0);

    cf = get_interest(ci,t,r);

    print_result(ci, t, r, cf);

    return 0;
}

double get_input(char msj[], double maxLim, double minLim){
    double n;

    do{
        printf("%s",msj);
        scanf("%lf", &n);
    } while(n<=minLim || n>maxLim);

    return n;
}

double get_interest(double ci, double t, double r){
    double cf = ci;

    for(unsigned i = 0; i < (unsigned)t; i++){
        cf *= (1 + r/100.0);
    }

    return cf;
}

void print_result(double ci, double t, double r, double cf){
    printf("\nCon una inversión inicial de %.2f,\n", ci);
    printf("a %.2f años,\n", t);
    printf("con tasa anual de %.2f%%,\n", r);
    printf("el capital final es: %.2f\n", cf);

    return;
}
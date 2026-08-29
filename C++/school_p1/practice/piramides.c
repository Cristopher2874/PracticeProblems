#include <stdio.h>

/* Prototipos */
int get_input(char msj[], int min, int max);
void print_piramide1(int N);
void print_piramide2(int N);
void print_piramide3(int N);
void print_all(int N);

int main() {

    int N;

    N = get_input("Ingrese un valor entre 1 y 9: ", 1, 9);

    printf("\nPirámide 1:\n");
    print_piramide1(N);

    printf("\nPirámide 2:\n");
    print_piramide2(N);

    printf("\nPirámide 3:\n");
    print_piramide3(N);

    print_all(N);

    return 0;
}

/* -------- FUNCIÓN DE ENTRADA -------- */
int get_input(char msj[], int min, int max) {

    int n;

    do {
        printf("%s", msj);
        scanf("%d", &n);
    } while(n < min || n > max);

    return n;
}

/* -------- PIRÁMIDE 1 -------- */
void print_piramide1(int N) {

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

/* -------- PIRÁMIDE 2 -------- */
void print_piramide2(int N) {

    for(int i = N; i >= 1; i--) {
        for(int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

/* -------- PIRÁMIDE 3 (centrada) -------- */
void print_piramide3(int N) {

    for(int i = 1; i <= N; i++) {

        /* Espacios */
        for(int s = 1; s <= N - i; s++) {
            printf("  ");
        }

        /* Números */
        for(int j = 1; j <= i; j++) {
            printf("%d ", j);
        }

        printf("\n");
    }
}

void print_all(int N) {

    for(int i = 1; i <= N; i++) {

        /* --- Pirámide 1 --- */
        for(int j = 1; j <= i; j++)
            printf("%d ", j);

        printf("          ");   // separación


        /* --- Pirámide 2 --- */
        for(int j = 1; j <= N - i + 1; j++)
            printf("%d ", j);

        printf("    ");   // separación


        /* --- Pirámide 3 --- */
        for(int s = 1; s <= N - i; s++)
            printf("  ");

        for(int j = 1; j <= i; j++)
            printf("%d ", j);

        printf("\n");
    }
}
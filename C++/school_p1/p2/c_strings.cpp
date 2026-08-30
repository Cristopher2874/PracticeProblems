#include <iostream>
#include <cstring>

using namespace std;

void desplegar_cadena(char *frase);

int main() {
    char frase[80];

    // nos ahorramos la funcion de entrada, es mas sencilla
    cout << "Ingrese una cadena: ";
    cin.getline(frase, 80);

    // si usamos una funcion para hacer la reversa
    desplegar_cadena(frase);

    cout << endl;
    
    return EXIT_SUCCESS;
}

/*
No estaba seguro si se referia a pasar la frase por punteros o usar 
punteros para hacer la inversion profe,
entonces pongo las dos versiones, aqui mas explicada porque es un poco mas compleja
lo unico que cambia con el otro programa es la funcion
*/
void desplegar_cadena(char *frase) {
    // strlen() devuelve la longitud de la cadena
    int longitud = strlen(frase);

    // guardamos un apuntador para el final de la cadena
    // en C cuando frase es un apuntador apunta al primer elemento del array, as[i que ]
    // podemos sumar la longitud y "mover" el puntero al final del array
    char *final = frase + (longitud - 1);

    // sacamos el valor desde el fial de la cadena
    // usamos el truco de comparar los punteors porque ambos son este tipo de dato
    while (final >= frase) {
        // aqui si sacamos el valor del puntero para imprimir
        cout << *final;
        final--;
    }

    return;
}
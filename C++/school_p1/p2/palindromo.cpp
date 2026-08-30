#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

void recibir_cadena(char *frase);
void quitar_espacios(char *frase);
bool verificar_palindromo(char *frase);
void imprimir_respuesta(char *frase, bool es_palindromo);

int main() {
    char frase[80];
    bool es_palindromo;

    recibir_cadena(frase);

    es_palindromo = verificar_palindromo(frase);

    imprimir_respuesta(frase, es_palindromo);

    return EXIT_SUCCESS;
}

void recibir_cadena(char *frase){
    cout << "Ingrese una cadena: ";
    cin.getline(frase, 80);

    return;
}

/*
Tambien aqui profe, no estaba seguro si habia que usar punteros,
asi que le envio la version donde igual que en el pasado,
obtenemos el final de la cadena para comparar
*/
bool verificar_palindromo(char *frase) {
    char *inicio = frase;
    // volvemos a usar el truco de final de frase
    char *fin = frase + strlen(frase) - 1;
    bool es_palindromo = true;

    while (es_palindromo && inicio < fin) {
        // saltar espacios al inicio
        while (*inicio == ' ' && inicio < fin) {
            inicio++;
        }

        // saltar espacios al final
        while (*fin == ' ' && inicio < fin) {
            fin--;
        }

        // ignorar mayusculas y minusculas, tambien sacamos el calor de los punteros
        if (tolower(*inicio) != tolower(*fin)) {
            es_palindromo = false;
        }

        inicio++;
        fin--;
    }

    return es_palindromo;
}

void imprimir_respuesta(char *frase, bool es_palindromo){
    
    if(es_palindromo){
        cout<<"La frase "<<frase<<" es palindromo";
    }else{
        cout<<"La frase "<<frase<<" no es palindromo";
    }
    
    return;
}
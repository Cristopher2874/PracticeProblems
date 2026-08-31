/*
3. Haga un programa que lea una cadena del teclado, usando la clase string, y despliegue su 
contenido en orden inverso, usando el operador [] y el método length(). 
*/

#include <iostream>
#include <string>

using namespace std;

string leer_frase();
void mostrar_string_inverso(string frase);

int main(){
    string frase;

    frase = leer_frase();
    mostrar_string_inverso(frase);

    return EXIT_SUCCESS;
}

string leer_frase(){
    string frase;

    cout<<"Ingrese una frase: ";
    getline(cin, frase);

    return frase;
}

void mostrar_string_inverso(string frase){
    char temp;
    int tam = frase.length();

    cout<<"Frase original: "<<frase<<endl;

    for(int i=0; i<tam/2; i++){
        temp = frase[i];
        frase[i] = frase[tam-i-1];
        frase[tam-i-1] = temp;
    }

    cout<<"Frase invertida: "<<frase<<endl;

    return;
}
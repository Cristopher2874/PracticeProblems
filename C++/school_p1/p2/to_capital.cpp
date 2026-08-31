/*
4. Haga un programa que lea una cadena de texto y la convierta en mayúsculas usando la clase 
string.
*/

#include <iostream>
#include <string>

using namespace std;

string leer_frase();
void convertir_a_mayusculas(string frase);

int main(){
    string frase;

    frase = leer_frase();
    convertir_a_mayusculas(frase);

    return EXIT_SUCCESS;
}

string leer_frase(){
    string frase;

    cout<<"Ingrese una frase: ";
    getline(cin, frase);

    return frase;
}

void convertir_a_mayusculas(string frase){
    int tam = frase.length();

    cout<<"Frase original: "<<frase<<endl;

    for(int i=0; i<tam; i++){
        frase[i] = toupper(frase[i]);
    }

    cout<<"Frase en mayusculas: "<<frase<<endl;

    return;
}
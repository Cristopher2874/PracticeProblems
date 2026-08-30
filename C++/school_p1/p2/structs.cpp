/*
1. Escriba un programa que haga lo siguiente: 
a) Declarar una estructura con al menos 4 campos, de al menos 3 tipos distintos (Ver ejemplo 
“Estructura Persona”). El tipo y campos de la estructura es libre (por ejemplo: libro, auto, etc.) 
b) Crear un arreglo de estructuras de tamaño 10, del mismo tipo que se declaró. 
c) Utilizando de un ciclo, solicitar al usuario los datos a almacenar en las estructuras, y llenar los 
campos de las estructuras en el arreglo. 
d) Utilizando un ciclo, desplegar el contenido del arreglo 
*/

#include <iostream>

using namespace std;

typedef struct{
    int agno_publicacion;
    bool saga;
    char nombre[40]; //cadena de 40 caracteres
    char epub[10]; //cadena 10 caracteres
}Libro;

void entrar_informacion(Libro &tomo);
void mostrar_informacion(Libro &tomo);

int main(){
    Libro grupo[10]; //arreglo de estructuras de tama;o 10

    //ciclo que sirve para rellenar los campos
    for(int i=0; i<10;i++){
        entrar_informacion(grupo[i]);
    }

    cout<<"Datos almacenados: "<<endl;

    for(int i=0; i<10;i++){
        mostrar_informacion(grupo[i]);
    }
    return EXIT_SUCCESS;
}

void entrar_informacion(Libro &tomo){
    cout<<"Introduce el nombre de tu libro (max. 40 caracteres): "<<endl;
    cin.getline(tomo.nombre, 40);
    cout<<tomo.nombre<<" es un buen tomo! Introduce el agno de publicacion: "<<endl;
    cin>>tomo.agno_publicacion;
    cin.ignore();
    cout<<"Se trata de una saga? (0 -> no / 1 -> si): "<<endl;
    cin>>tomo.saga;
    cin.ignore();
    cout<<"Finalmente, revisemos el EPU (10 caracteres): "<<endl;
    cin>>tomo.epub;
    cin.ignore();
    return;
}

void mostrar_informacion(Libro &tomo){
    cout<<"Informacion sobre: "<<tomo.nombre<<endl;
    cout<<"Publicado el agno: "<<tomo.agno_publicacion<<endl;
    cout<<"Parte de una saga: "<<tomo.saga<<endl;
    cout<<"Datos de EPUB: "<<tomo.epub<<endl;
    return;
}
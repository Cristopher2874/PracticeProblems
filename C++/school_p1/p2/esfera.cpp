/*
2. Escriba una función llamada esfera, la cual recibe como parámetro el radio de una esfera y 
despliega su volumen y el área de su superficie. Escriba una función principal en la cual, dentro de 
un ciclo que se repite mientras el usuario no indique que desea terminar, se solicite al usuario el 
radio de la esfera y se haga una llamada a la función esfera. 
*/

#include <iostream>
#define PI 3.1416

using namespace std;

double leer_radio(string mensaje);
void esfera(double radio);

int main(){
    double radio;

    do{
        radio = leer_radio("Entrar el radio (valor positivo) de la esfera, 0 para terminar: ");
        if(radio > 0){
            esfera(radio);
        }
    }while(radio != 0);

    cout<<"Programa terminado"<<endl;
    
    return EXIT_SUCCESS;
}

double leer_radio(string mensaje){
    double radio;

    cout<<mensaje<<endl;
    cin>>radio;

    return radio;
}

void esfera(double radio){
    double area = 4 * PI * radio * radio;
    double volumen = (4.0 / 3.0) * PI * radio * radio * radio;

    cout<<"El area de la esfera con radio "<<radio<<" es "<<area<<endl;
    cout<<"El volumen de la esfera con radio "<<radio<<" es "<<volumen<<endl;
}
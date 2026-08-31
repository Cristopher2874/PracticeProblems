/*
1. Modifique el ejemplo “plantillas_funciones_2” para que se trabaje con tipos int, float, double y 
char. Utilice los conceptos vistos para asegurar que se escriba la menor cantidad de código posible. 
En la función main agregue el código para que se soliciten al usuario tres datos de cada tipo, y en 
cada caso se obtenga y despliegue el valor máximo.
*/
#include <iostream>
#include <string>

using namespace std;

template <class T>
T maximo( T valor1, T valor2, T valor3 ){
   T max = valor1; 

   if ( valor2 > max )
      max = valor2;
   if (valor3 > max )
      max = valor3;

   return max;
}

template <class T>
void recibir_valores(string mensaje, T *valor1, T *valor2, T *valor3){
    cout<<mensaje;
    cin>>*valor1>>*valor2>>*valor3;
    return;
}

int main ()
{
   int entero1, entero2, entero3;
   float float1, float2, float3;
   double double1, double2, double3;
   char char1, char2, char3;

   recibir_valores("Ingrese 3 valores enteros separados por espacios: ", &entero1, &entero2, &entero3);
   cout << "Maximo: " << maximo(entero1, entero2, entero3) << endl; 

   recibir_valores("Ingrese 3 valores floats separados por espacios: ", &float1, &float2, &float3);
   cout << "Maximo: " << maximo(float1, float2, float3) << endl; 

   recibir_valores("Ingrese 3 valores doubles separados por espacios: ", &double1, &double2, &double3);
   cout << "Maximo: " << maximo(double1, double2, double3) << endl; 

   recibir_valores("Ingrese 3 valores chars separados por espacios: ", &char1, &char2, &char3);
   cout << "Maximo: " << maximo(char1, char2, char3) << endl; 
   
   return EXIT_SUCCESS; 
}
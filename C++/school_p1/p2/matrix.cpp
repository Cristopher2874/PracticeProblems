/*
5. Haga un programa que declare dos matrices cuadradas de tamaño fijo que almacenan números 
de tipo double. El programa pide al usuario que proporcione los datos que se almacenarán en las 
dos matrices. Después, realiza la suma, resta, multiplicación y división, y despliega los resultados. 
Los valores de las matrices con los resultados deben mostrarse alineados, utilizando cout.
*/

// para que el cout pueda tener formatos
#include <iomanip>
#include <iostream>
#include <string>
#define N 200

using namespace std;

void leer_matrix(string message, double matrix[N][N], int tam);
void suma_matrix(double matrix1[N][N], double matrix2[N][N], double matrix_res[N][N], int tam);
void resta_matrix(double matrix1[N][N], double matrix2[N][N], double matrix_res[N][N], int tam);
void producto_matrix(double matrix1[N][N], double matrix2[N][N], double matrix_res[N][N], int tam);
void cociente_matrix(double matrix1[N][N], double matrix2[N][N], double matrix_res[N][N], int tam);
void imprimir_matrix(string message, double matrix[N][N], int tam);
int leer_valor(string message);

int main(){
    int tam = 0;
    double matrix1[N][N], matrix2[N][N], matrix_res[N][N];
    
    tam = leer_valor("Ingresa el tamano de la matriz (entero positivo): ");
    

    leer_matrix("Ingrese los elementos de la primera matriz separados por espacios y renglones por enter: ", matrix1, tam);
    leer_matrix("Ingrese los elementos de la segunda matriz separados por espacios y renglones por enter: ", matrix2, tam);
    
    suma_matrix(matrix1, matrix2, matrix_res, tam);
    imprimir_matrix("Matriz sumada: ", matrix_res, tam);

    resta_matrix(matrix1, matrix2, matrix_res, tam);
    imprimir_matrix("Matriz restada: ", matrix_res, tam);
    
    producto_matrix(matrix1, matrix2, matrix_res, tam);
    imprimir_matrix("Producto matricial: ", matrix_res, tam);

    cociente_matrix(matrix1, matrix2, matrix_res, tam);
    imprimir_matrix("Cociente elemento a elemento: ", matrix_res, tam);

    return 0;
}

int leer_valor(string message){
    int valor;
    cout<<message;

    do{
        cin>>valor;
    }while(valor <= 0 || valor > N);

    return valor;
}

void leer_matrix(string message, double matrix[N][N], int tam){
    cout<<message<<endl;
    for(int i=0; i<tam; i++){
        for(int j=0;j<tam;j++){
            cin>>matrix[i][j];
        }
    }
    
    return;
}

void suma_matrix(double matrix1[N][N], double matrix2[N][N], double matrix_res[N][N], int tam){
    for(int i=0; i<tam; i++){
        for(int j=0;j<tam;j++){
            matrix_res[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return;
}

void resta_matrix(double matrix1[N][N], double matrix2[N][N], double matrix_res[N][N], int tam){
    for(int i=0; i<tam; i++){
        for(int j=0;j<tam;j++){
            matrix_res[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return;
}

void producto_matrix(double matrix1[N][N], double matrix2[N][N], double matrix_res[N][N], int tam){
    for(int i=0; i<tam; i++){
        for(int j=0;j<tam;j++){
            matrix_res[i][j] = 0;
            for(int k=0; k<tam; k++){
                matrix_res[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return;
}

void cociente_matrix(double matrix1[N][N], double matrix2[N][N], double matrix_res[N][N], int tam){
    for(int i=0; i<tam; i++){
        for(int j=0;j<tam;j++){
            if(matrix2[i][j] == 0){
                cout << "Division indefinida en [" << i << "][" << j << "]" << endl;
                matrix_res[i][j] = 0;
            } else {
                matrix_res[i][j] = matrix1[i][j] / matrix2[i][j];
            }
        }
    }
    return;
}

void imprimir_matrix(string message, double matrix[N][N], int tam){
    cout<<message<<endl;
    cout << fixed << setprecision(2);
    for(int i=0; i<tam; i++){
        for(int j=0;j<tam;j++){
            cout << setw(12) << matrix[i][j];
        }
        cout<<endl;
    }
    cout<<endl;

    return;
}
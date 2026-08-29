/*
Program: compare_numbers.c
Description: create a program that prints true or false based on the input from the user about two numbers and a symbol
Input: int n1 first number, char s operation to verify, int n2 second number
Output: int result 1 for true, 0 for false (since C does not have a boolean data type)
Autor: Cristopher Hernandez
Date: 10.02.2026
*/

#include <stdio.h>

int get_data(char msj[]);
char get_s(char msj[]);
int compare_numbers(int n1, char s, int n2);
void print_result(int result);

int main(){
    int n1, n2, result;
    char s;

    n1 = get_data("Enter the first number to compare: ");
    n2 = get_data("Enter the second number to compare: ");
    s = get_s("Enter the operation to verify ('<', '>'): ");

    result = compare_numbers(n1, s, n2);

    print_result(result);
}

int get_data(char msj[]){
    int data;
    printf("%s", msj);
    scanf("%d", &data);
    return data;
}

char get_s(char msj[]){
    char s;
    printf("%s", msj);
    scanf("%c", &s);
    scanf("%c", &s);
    return s;
}

int compare_numbers(int n1, char s, int n2){
    int result;
    switch (s){
    case '<':
        result = n1 < n2;
        break;
    case '>':
        result = n1 > n2;
        break;
    default:
        result = -1;
        break;
    }
    return result;
}

void print_result(int result){
    switch (result){
    case 1:
        printf("True");
        break;
    case 0:
        printf("False");
        break;
    default:
        printf("Error: Invalid operation");
        break;
    }
}
/*
Program: combine numbers.c
Description: create a program that will receive two decimal numbers, in case the number of digits are the same, the program should merge the digits one from the second number, one for the first until all are done.
If the first number has more digits, the program will put one digit of the first number and then 0 intercalated, until you reach the number of digits of second number, then from there will intercalate the digits of the second and first number until all are done.
If the second number has more digits, the program will put the digits of the second number until reach the number of digits of the first number and then intercalate them until done.
Input: int n1 first number, int n2 second number
Output: int n result of the combination of the two numbers
Autor: Cristopher Hernandez
Date: 19.02.2026
*/

#include <stdio.h>

int get_data(char msj[], int supLimit, int infLimit);
int combine_numbers(int n1, int n2);
void print_result(int n);

int main(){
    int n1, n2, n;

    n1 = get_data("Enter the first number to merge: ", 999999, 0);
    n2 = get_data("Enter the second number to merge: ", 999999, 0);

    n = combine_numbers(n1, n2);

    print_result(n);
}

int get_data(char msj[], int supLimit, int infLimit){
    int data;
    do {
        printf("%s", msj);
        scanf("%d", &data);
    }while (data > supLimit || data < infLimit);

    return data;
}

int combine_numbers(int n1, int n2){
    int n = 0, flag = 1, mult = 1;
    
    // first we get the merge with same lenght
    while(n1!= 0 && n2 != 0){
        if(flag){
            n = n + (n2%10)*mult;
            n2 /= 10;
        }else{
            n = n + (n1 % 10)*mult;
            n1 /= 10;
        }
        flag = !flag;
        mult *= 10;
    }

    // we add the remaining digits depending on the case
    if(n1!=0){
        while(n1 != 0){
            n = n + (n1 % 10)*mult;
            n1 /= 10;
            mult *= 10;
            if(n1 != 0){
            n = n + 0*mult;
            mult *= 10;
            }
        }
    }else{
        while(n2 != 0){
            n = n + (n2 % 10)*mult;
            n2 /= 10;
            mult *= 10;
        }
    }

    return n;
}   

void print_result(int n){
    printf("The combination of the numbers is: %d\n", n);
}
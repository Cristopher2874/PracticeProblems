/*
Program: fractions.c
Description: create a program that operates two fractions given by the user
Input: int n1 first numerator, int d1 first denominator, 
int n2 second numerator, int d2 second denominator
Output: int rn result numerator, int rd result denominator
Autor: Cristopher Hernandez
Date: 04.02.2026
*/

//Libraries
#include <stdio.h>

//Function prototypes
int get_data(char msj[]);
char get_symbol(char msj[]);
int operate_sections(int n1, int d1, int n2, int d2, char symbol, int op_place);
int get_gdc(int rn, int rd);
int simplify_result(int v1, int gdc);
void print_result(int n1, int d1, char symbol, int n2, int d2, int rn, int rd);

int main(){
    int n1, n2, d1, d2, rn, rd, gdc;
    char symbol;

    n1 = get_data("Enter the numerator of first fraction\n");
    d1 = get_data("Enter the denominator of first fraction\n");
    n2 = get_data("Enter the numerator of second fraction\n");
    d2 = get_data("Enter the denominator of second fraction\n");
    symbol = get_symbol("Enter the operation to perform <'+', '-', '*', '/'>");

    rn = operate_sections(n1, d1, n2, d2, symbol, 1); //numerator result
    rd = operate_sections(n1, d1, n2, d2, symbol, 2); //denominator result

    // calculate in case the fraction can be simplified
    gdc = get_gdc(rn, rd);

    // get the new results
    rn = simplify_result(rn, gdc);
    rd = simplify_result(rd, gdc);

    print_result(n1, d1, symbol, n2, d2, rn, rd);
}

int get_data(char msj[]){
    int data;
    printf("%s", msj);
    scanf("%d", &data);
    return data;
}

char get_symbol(char msj[]){
    char symbol;
    printf("%s", msj);
    scanf(" %c", &symbol);
    return symbol;
}

int operate_sections(int n1, int d1, int n2, int d2, char symbol, int op_place){
    int result;
    if(op_place == 1){ //numerator
        if(symbol == '+'){ //addition
            result = n1 * d2 + n2 * d1;
        }
        else if(symbol == '-'){ //subtraction
            result = n1 * d2 - n2 * d1;
        }
        else if(symbol == '*'){ //multiplication
            result = n1 * n2;
        }
        else if(symbol == '/'){ //division
            result = n1 * d2;
        }
        else{
            result = 0;
        }
    }
    else if(op_place == 2){ //denominator
        if(symbol == '+' || symbol == '-'){ //addition and subtraction
            result = d1 * d2;
        }
        else if(symbol == '*'){ //multiplication
            result = d1 * d2;
        }
        else if(symbol == '/'){ //division
            result = d1 * n2;
        }
        else{
            result = 0;
        }
    }
    return result;
}

// calculate the greatest common divisor (gdc)
int get_gdc(int rn, int rd){
    int gcd, temp_rn, temp_rd;
    temp_rn = rn;
    temp_rd = rd;

    while(temp_rd != 0){
        gcd = temp_rd;
        temp_rd = temp_rn % temp_rd;
        temp_rn = gcd;
    }
    return gcd;
}

// symplifies the fraction using GDC
int simplify_result(int v1, int gdc){
    int simplified;
    if (gdc == 0){
        simplified = v1;
    }else{
        simplified = v1 / gdc;
    }
    return simplified;
}

//prints the result
void print_result(int n1, int d1, char symbol, int n2, int d2, int rn, int rd){
    if(d1==0 || d2==0){
        printf("Error: Denominator cannot be zero");
    }else if(symbol != '+' && symbol != '-' && symbol != '*' && symbol != '/'){
        printf("Error: Invalid operation");
    }else{
        printf("The result of %d/%d %c %d/%d is: %d/%d", n1, d1, symbol, n2, d2, rn, rd);
    }
    return;
}
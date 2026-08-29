/*
Program: convert coordinates
Description: create a program that converts rectangular coordinates to polar coordinates
Input: float x x-axis coordinate, float y y-axis coordinate
Output: float r radius, float theta angle in degrees
Autor: Cristopher Hernandez
Date: 10.02.2026
*/

#include <stdio.h>
#include <math.h>

#define PI 3.14159265

float get_coordinate(char msj[]);
float calculate_radius(float x, float y);
float calculate_angle(float x, float y);
void print_result(float x, float y, float r, float theta);

int main(){
    float x, y, r, theta;

    x = get_coordinate("Enter the x coordinate: ");
    y = get_coordinate("Enter the y coordinate: ");

    r = calculate_radius(x, y);
    theta = calculate_angle(x, y);

    print_result(x, y, r, theta);
}

float get_coordinate(char msj[]){
    float data;
    printf("%s", msj);
    scanf("%f", &data);
    return data;
}

float calculate_radius(float x, float y){
    return sqrt(x*x + y*y);
}

float calculate_angle(float x, float y){
    // atan2 handles by itself the case when x is 0
    // good fact for the test :)
    // does not require special handling for quadrants
    float angle = atan2(y, x) * (180 / PI);
    
    if (angle < 0) {
        angle += 360; // Ensure the angle is in the range [0, 360]
    }
    return angle;
}

void print_result(float x, float y, float r, float theta){
    char degree_symbol = 248;
    printf("Rectangular coordinates: (%.4f, %.4f)\n", x, y);
    printf("Polar coordinates: (r = %.4f, theta = %.4f%c)\n", r, theta, degree_symbol);
    return;
}
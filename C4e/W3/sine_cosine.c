/*
Write a C program that has a function that prints a table of values for 
sine and cosine between (0, 1). Upload your program as a text file. 
*/
#include <stdio.h>
#include <math.h>

void print_sine_cosine_table();

int main(void) {
    print_sine_cosine_table();
    return 0;
}

void print_sine_cosine_table() {
    double value;
    printf("Value\t\tSine value\t\tCosine\n");
    printf("---------------------------------------\n");
    
    for (value = 0.0; value <= 1.0; value += 0.1) {
        printf("%.2lf\t\t%.6lf\t%.6lf\n", value, sin(value), cos(value));
    }
}
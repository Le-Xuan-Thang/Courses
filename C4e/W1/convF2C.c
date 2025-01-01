/*
    Conversion of Fahreheit to Celsius
    C = (F - 32)/1.8
    Sally Coder
    August 30,2017
*/
#include <stdio.h>

int main(void)
{
    double F, C;
    printf("Enter the temperature in Fahreheit degees:");
    scanf("%lf", &F);
    C = (F - 32)/1.8;
    printf("The temperature in Celsius is %.2lf\n", C);
    return 0;
}


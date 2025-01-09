/*
    Circle and Area
    Sally Coder
    Sept. 16, 2016
*/

#include <stdio.h>

#define PI 3.14159

int main() {
    double radius;
    double area;

    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius); // %lf is used to read a double value

    area = PI * radius * radius;

    printf("The area of the circle is: %lf\n", area); // %lf is used to print a double value

    return 0;
}

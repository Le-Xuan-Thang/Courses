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
    scanf("%lf", &radius);

    area = PI * radius * radius;

    printf("The area of the circle is: %lf\n", area);

    return 0;
}

#include<stdio.h>

int main() {
    double a = 1, b = 2, c = 3;
    int cal;

    // Perform calculations
    cal = a++ + --b;  // a is incremented after the operation, b is decremented before

    // Print the values of a, b, c
    printf("a = %lf\n", a); // After a++, a will be incremented
    printf("b = %lf\n", b); // After --b, b will be decremented
    printf("c = %lf\n", c); // c remains unchanged

    // Print the result of the calculation
    printf("result is %d\n", cal);

    return 0;
}

/*Circle
    by Thang
    Jan, 2025
*/

#include<stdio.h>
#define PI 3.14159
int main(void)
{ 
    double radius;
    int a = 3, b = 4, c = -2;
    printf("Enter radius:");
    scanf("%lf", &radius); // Corrected format specifier to %lf
    printf("volume is : %lf \n\n", (4.0/3.0) * PI * radius * radius * radius);
    
    printf("a + b = %d\n", a + b);
    printf("-a + b = %d\n", -a + b);
    printf("++a + c = %d\n", ++a + c); // This will print 2
    printf("a / b = %d\n", a / b);
    printf("b / a = %d\n", b / a);
    printf("++a + b++ = %d\n", ++a + b++);
    return 0;
}
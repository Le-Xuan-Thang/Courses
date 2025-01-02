/*Kilometers conversion
    By Thang
    Jan, 2025
*/
#include <stdio.h>

int main(void)
{
    int miles=26, yards=385;
    int kilometers;
    kilometers = 1.609 * (miles + yards/1760.0);
    printf("The distance in kilometers is %lf km \n", kilometers);
    return 0;
}
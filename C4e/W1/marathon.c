/*
    The distance of a marathone in kilometers
    by Sammy Coder
    April 18, 2018
*/

#include <stdio.h>

int main (void){
    int miles = 26;
    int yards = 385;
    double kilometers;

    kilometers = 1.609 * (miles + yards / 1760.0);
    printf("A marathon is %lf kilometers.\n", kilometers);
    return 0;
}
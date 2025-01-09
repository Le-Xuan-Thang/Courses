/* Table of squares and cubes
 * Function prototypes
 * Sally Coder 18 Jan, 2018
 */

#include <stdio.h>
#include <math.h>

// Function prototypes
double square(double);
double cube(double);

int main(void)
{
    int how_many = 0, i, j;
    printf("I want square and cube for 1 to n where n is: ");
    scanf("%d", &how_many);

    printf("\n Square and cubes by interval of 0.1 \n");

    // Generate the table of squares and cubes
    for (i = 1; i <= how_many; i++)
    {
        for (j = 0; j < 10; j++)
        {
            double value = i + j / 10.0;
            printf("%6.1lf\t%10.3lf\t%10.3lf\n", value, square(value), cube(value));
        }
    }

    printf("\n\n");
    return 0;
}

// Function to calculate the square of a number
double square(double x)
{
    return x * x;
}

// Function to calculate the cube of a number
double cube(double x)
{
    return x * x * x;
}
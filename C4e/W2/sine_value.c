#include <stdio.h>
#include <math.h>

int main(void) {
    double value;
    double sine_value;
    printf("Enter a value between 0 and 1 (non-inclusive): ");
    scanf("%lf", &value);

    if (value <= 0 || value >= 1) {
        printf("Error: Value must be between 0 and 1 (non-inclusive).\n");
        return 1;
    }

    sine_value = sin(value);
    printf("The sine of %.2lf is %.2lf\n", value, sine_value);

    return 0;
}

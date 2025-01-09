#include <stdio.h>
#include <stdlib.h>

#define MAX_WEIGHTS 10000  // Assuming a maximum of 10,000 weights for simplicity

int main() {
    FILE *file;
    char filename[] = "elephant_seal_data.txt";
    int weights[MAX_WEIGHTS];  // Array to store weights
    int count = 0;             // Counter for the number of weights
    long long sum = 0;         // Variable to store the sum of weights

    // Open the file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }

    // Read the weights into the array
    while (fscanf(file, "%d", &weights[count]) == 1) {
        sum += weights[count];  // Add weight to the sum
        count++;

        // Check if we exceed the array size
        if (count >= MAX_WEIGHTS) {
            printf("Error: Too many weights in the file (exceeds %d).\n", MAX_WEIGHTS);
            fclose(file);
            return 1;
        }
    }

    fclose(file);  // Close the file

    // Check if any weights were read
    if (count == 0) {
        printf("No data found in the file.\n");
        return 1;
    }

    // Calculate and print the average
    double average = (double)sum / count;
    printf("The average weight of the elephant seals is: %.2f\n", average);

    return 0;
}

// P1 Assignment
// Author: Chris Wilcox
// Date:   1/8/2016
// Class:  CS270
// Email:  wilcox@cs.colostate.edu

// Include files
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void computeSphere(double radius, double *addressOfVolume)
{
    // Compute volume
    double result = (4.0 / 3.0) * (3.141593 * radius * radius * radius);

    // Dereference pointer to return result
    *addressOfVolume = result;
}

int main(int argc, char *argv[])
{
    // Check number of arguments
    if (argc != 2) {
        printf("usage: ./P1 <double>\n");
        return EXIT_FAILURE;
    }

    // Parse arguments
    double radius = atof(argv[1]);
    
    // Local variable
    double volume;

    // Call function
    computeSphere(radius, &volume);
    
    // Print volume
    printf("The volume of a sphere with radius %.5f equals %.5f.\n", radius, volume);

    // Return success
    return EXIT_SUCCESS;
    }

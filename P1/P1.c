// P1 Assignment
// Author: Habeeb Mohammed
// Date:   1/8/2016
// Class:  CS270
// Email:  habeeb@cs.colostate.edu

// Include files
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static double input[4];
static double output[4];

void computeCircle(double radius, double *addressOfArea)
{
	
	//Compute area
	double result = 3.141593 * (radius * radius);

	//Dereference pointer to return result
	*addressOfArea = result;
}

void computeTriangle(double side, double *addressOfArea)
{
	
	//Compute area
	double result = .433013 * (side * side);

	//Dereference pointer to return result
	*addressOfArea = result;
}

void computeSquare(double side, double *addressOfArea)
{
	
	//Compute area
	double result = side * side;

	//Dereference pointer to return result
	*addressOfArea = result;
}

void computePentagon(double side, double *addressOfArea)
{
	
	//Compute area
	double result = 1.720477 * (side * side);

	//Dereference pointer to return result
	*addressOfArea = result;
}

int main(int argc, char *argv[])
{
	
	//double radiusCircle = 0.0;
	//double sideTriangle = 0.0;
	//double sideSquare = 0.0;
	//double sidePentagon = 0.0;

    // Check number of arguments
    if (argc != 5)	 
    {	
	//printf("%d\n",argc);
        printf("usage: ./P1 <double> <double> <double> <double>\n");
        return EXIT_FAILURE;
    }
	// Parse arguments
		input[0] = atof(argv[1]);
		input[1] = atof(argv[2]);
		input[2] = atof(argv[3]);
		input[3] = atof(argv[4]);

	// Local variables
		//double areaCircle;
		//double areaTriangle;
		//double areaSquare;
		//double areaPentagon;


    // Call functions
    	computeCircle(input[0], &output[0]);
	computeTriangle(input[1], &output[1]);
	computeSquare(input[2], &output[2]);
	computePentagon(input[3], &output[3]);

    // Print volume
	printf("CIRCLE, radius = %.5f, area = %.5f.\n", input[0], output[0]);
	printf("TRIANGLE, length = %.5f, area = %.5f.\n", input[1], output[1]);
	printf("SQUARE, length = %.5f, area = %.5f.\n", input[2], output[2]);
	printf("PENTAGON, length = %.5f, area = %.5f.\n", input[3], output[3]);


    // Return success
    return EXIT_SUCCESS;
    }

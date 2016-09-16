// File:        main.c
// Description: ... fill this in
// Author:      ... fill this in
// Date:        ... fill this in
// Email:       ... fill this in

// Include files
#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
// TODO: add include for printf/scanf
// TODO: add include for malloc/free

// Function:     main
// Description:  entry point

Student *students;  
int main()
{
	int x;
	scanf("%d", &x);
	printf("Enter number of students: %d", x);
	
	Student sArray[x];
	students = malloc(x * sizeOf(sArray));

	free(sArray);
    return 0;
}

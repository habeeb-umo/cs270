// File:        struct.c
// Description: ... fill this in
// Author:      ... fill this in
// Date:        ... fill this in
// Email:       ... fill this in

// Include files
#include "struct.h"
#include <stdio.h>
// TODO: add include for printf/scanf

// Input scores
void inputScores(Student *student){
	char fName;
	scanf("%s", fName);
	printf("Enter the first name: %s", fName);
	*student.firstName = fName;

	char lName;
	scanf("%s", lName);
	printf("Enter the last name: %s", lName);
	*student.lastName = lName;
	
	int avgHw;
	scanf("%d", avgHw);
	printf("Enter the average homework score: %d", avgHw);
	*student.avgHw = avgHw;
	
	int avgLab;
	scanf("%d", avgHw);
	printf("Enter the average lab score: %d", avgLab);
	*student.avgLab = avgLab;	

	int midterm;
	scanf("%d", midScore);
	printf("Enter the midterm: %d", midScore);
	*student.midScore = midScore;

	int avgHw;
	scanf("%d", finScore);
	printf("Enter the final exam score: %d", finScore);
	*student.finScore = finScore;
}
// Output scores
void outputScores(Student student){

	printf("First name: %s\n
		Last name: %s\n
		Average homework score: %d\n
		Average lab score: %d\n
		Midterm score: %d\n
		Final exam score: %d\n
		", *student.firstName, *student.lastName,
		*student.avgHw, *student.avgLab, *student.midScore,
		*student.finScore);

}
// Calculate scores



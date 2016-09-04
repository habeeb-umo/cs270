/**
 *  Habeeb Mohammed
 *  9/4/2016
 *  CS 270
 *  habeeb@cs.colostate.edu
 */

#include <stdlib.h>
#include <stdio.h>
/** @todo implement in <code>numconv.c</code> based on documentation contained 
 *  in <code>numconv.h</code>.
 */
char int2char (int radix, int digit) {

	char cFinal;

	// radix be less than number and radix must be between 2 and 36
	if(digit >= radix || radix < 2 || radix > 36) 
	{
		cFinal = '?';
	}
	else
	{
		// 0-9
		if(digit < 10 && digit >= 0) {
			cFinal = '0' + digit;
			return cFinal;
		}
		else
			cFinal = '?';
		// A-Z
		if(digit >= 10 && digit < 36) {
			cFinal = '7' + digit;
			return cFinal;
		}
		else
			cFinal = '?';
	}
	
	return cFinal;
}

/** @todo implement in <code>numconv.c</code> based on documentation contained 
 *  in <code>numconv.h</code>.
 */
int char2int (int radix, char digit) {

  	int numFinal = -1;

	// radix must be between 2 and 36
	if(radix < 2 || radix > 36) 
	{
		return -1;
	}
	else
	{
		// 0-9
		if(digit <= '9' && digit >= '0') {
			if(radix <= (digit - 48)){
				return -1;
			}
			numFinal = digit - 48;
			return numFinal;
		}
		else
			numFinal = -1;
		// A-Z
		if(digit >= 'A' && digit <= 'Z') {
			if(radix <= (digit - 55)){
				return -1;
			}
			numFinal = digit - 55;
			return numFinal;
		}
		else
			numFinal = -1;
		// a-z
		if(digit >= 'a' && digit <= 'z') {
			if(radix <= (digit - 87)){
				return -1;
			}
			numFinal = digit - 87;
			return numFinal;
		}
		else
			numFinal = -1;

		return numFinal;
	}

	return numFinal;
}

/** @todo implement in <code>numconv.c</code> based on documentation contained 
 *  in <code>numconv.h</code>.
 */
void divRem (int numerator, int divisor, int* quotient, int* remainder) {

	int rFinal;
	int qFinal;

	// Quotient and modulo formulas
	rFinal = numerator % divisor;
	qFinal = numerator / divisor;

	// Return via pointers
	*remainder = rFinal;
	*quotient = qFinal;
}

/** @todo implement in <code>numconv.c</code> based on documentation contained 
 *  in <code>numconv.h</code>.
 */
int ascii2int (int radix, const char *str) {

	int numFinal;
	char *endptr;

	// radix must be between 2 and 36
	if(radix < 2 || radix > 36)
	{
		return -1;
	}
	else
	// strtol(str, &endptr, base) is string to long int
	numFinal = strtol(str, &endptr, radix);

  return numFinal;
}

/** @todo implement in <code>numconv.c</code> based on documentation contained 
 *  in <code>numconv.h</code>.
 */
void int2ascii (int radix, int value) {
	
	// base case
	if(value <= 0){

	}
	// recursive case
	else{

		int2ascii(radix, value / radix);
		putchar(int2char(radix,value % radix));
	}
}

/** @todo implement in <code>numconv.c</code> based on documentation contained 
 *  in <code>numconv.h</code>.
 */
double ascii2double (int radix, const char *str) {
	
	double dFinal;
	char *endPtr;
	
	if(radix < 2 || radix > 36)
	{
		return -1.0;
	}
  	else
	dFinal = strtod(str, &endPtr);

return dFinal;
}


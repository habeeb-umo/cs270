#include "flt32.h"
#include <stdio.h>
#include <stdlib.h>
/** @file flt32.c
 *  @brief You will modify this file and implement nine functions
 *  @details Your implementation of the functions defined in flt32.h.
 *  You may add other function if you find it helpful. Added function
 *  should be declared <b>static</b> to indicate they are only used
 *  within this file.
 *  <p>
 *  @author <b>Your name</b> goes here
 */

void printBinary (int value);

int flt32_get_sign (flt32 x){
	
	// 31 & 1 clears (1,31) leaving only sign bit
	return x >> 31 & 1; 
}

int flt32_get_exp (flt32 x) {

	x = x >> 23;
	int field = (8 - 0) + 1;
	int mask = (1 << field) - 1;
  
	return x & mask;
}

int flt32_get_val (flt32 x) {
	
	// Mantissa = (0,23)
	int field = (22 - 0) + 1;
	int mask = (1 << field) - 1;

	// 8388608 = implicit 1;	
  	return (x & mask) + 8388608;
}

void flt32_get_all(flt32 x, int* sign, int*exp, int* val) {

	*sign = flt32_get_sign(x); 
	*exp = flt32_get_exp(x);
	*val = flt32_get_val(x);
}

/** @todo Implement in flt32.c based on documentation contained in flt32.h */
flt32 flt32_abs (flt32 x) {
		
	return (x & 2147483647);
}

/** @todo Implement in flt32.c based on documentation contained in flt32.h */
flt32 flt32_negate (flt32 x) {

	if(x == 0)
	return 0;

	return x ^ 1 << 31;
}

/** @todo Implement in flt32.c based on documentation contained in flt32.h */
flt32 flt32_add (flt32 x, flt32 y) {
	// Get all x components
	int xSign = flt32_get_sign(x);
	int xExp = flt32_get_exp(x);
	int xVal = flt32_get_val(x);

	// Get all y components
	int ySign = flt32_get_sign(y);
	int yExp = flt32_get_exp(y);
	int yVal = flt32_get_val(y);
	
	// Equalize
	if(x > y){
	y = y >> (x - y);
	yExp = yExp + (x - y);
	}
	if(y > x){
	x = x >> (x - y);
	xExp = xExp + (x - y);
	}

	
	int resultSign;
	if((x > y) && (xSign == 1))
	resultSign = 1;
	if((y > x) && (ySign == 1))
	resultSign = 1;
	else
	resultSign = 0;
	
	if(xSign = 1)
	x = ~x + 1;
	if(ySign = 1)
	y = ~y + 1;
	
	int result = x + y;
	//int resultExp = xExp;
	
	
  return result;
}

/** @todo Implement in flt32.c based on documentation contained in flt32.h */
flt32 flt32_sub (flt32 x, flt32 y) {
  return 0;
}
	

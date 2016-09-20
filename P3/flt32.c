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

int getBit (int value, int position) {
    //requires right shift & modulo
	int mask = 1;
	value = value >> position;
	return value & mask;
}
int clearBit (int value, int position) {
	int mask = 1 << position;
   	 return ~(mask) & value;

}

int howDisplaced(int val){
	int dCount = 0;
	for(int i = 31; i >= 0; i--){
	if(getBit(val, i) == 1){
		return 31 - dCount;
	}
	else
		dCount += 1;
	}
	return dCount;
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
	
	// Equalize exponents
	int resExp;
	if(xExp > yExp){
	yVal = yVal >> (xExp - yExp);
	yExp = yExp + (xExp - yExp);
	resExp = xExp;
	}
	if(yExp > xExp){
	xVal = xVal >> (yExp - xExp);
	xExp = xExp + (yExp - xExp);
	resExp = yExp;
	}
	// Negative sign?
	int resSign = 0;
	if(xSign == 1){
	x = ~x + 1;
	resSign = 1;
	}
	if(ySign == 1){
	y = ~y + 1;
	resSign = 1;
	}
	
	// Result mantissa
	int resVal = xVal + yVal;

	// Convert to 2's comp 
	if(resSign == 1)
	resVal = ~resVal + 1;

	// Normalize Result
	if(23 - howDisplaced(resVal) < 0){
	int dispLeft = (23 - howDisplaced(resVal)) * (-1);
	resVal = resVal >> dispLeft;
	resExp = resExp + dispLeft; 
	}
	if(23 - howDisplaced(resVal) > 0){
	int dispRight = 23 - howDisplaced(resVal);
	resVal = resVal << dispRight;
	resExp = resExp + dispRight;
	}
	// Finalize position
	resExp = resExp << 23;
	resVal = clearBit(resVal, 23);
	
  return xSign | resExp | resVal;
}

/** @todo Implement in flt32.c based on documentation contained in flt32.h */
flt32 flt32_sub (flt32 x, flt32 y) {
	printBinary(flt32_add(x,~y));
  return flt32_add(x,~y);
}
	

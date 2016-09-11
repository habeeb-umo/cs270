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
  return 0;
}

/** @todo Implement in flt32.c based on documentation contained in flt32.h */
flt32 flt32_negate (flt32 x) {
  return 0;
}

/** @todo Implement in flt32.c based on documentation contained in flt32.h */
flt32 flt32_add (flt32 x, flt32 y) {
  return 0;
}

/** @todo Implement in flt32.c based on documentation contained in flt32.h */
flt32 flt32_sub (flt32 x, flt32 y) {
  return 0;
}


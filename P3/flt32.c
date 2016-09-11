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

/** @todo Implement in flt32.c based on documentation contained in flt32.h */
int flt32_get_sign (flt32 x){

	return x >> 31 & 1; /* implement this */
}

/** @todo Implement in flt32.c based on documentation contained in flt32.h */
int flt32_get_exp (flt32 x) {
	x = x >> 23;
	int field = (8 - 0) + 1;
	int mask = (1 << field) - 1;
	printf("\n");
  
	return x & mask; /* implement this */
}

/** @todo Implement in flt32.c based on documentation contained in flt32.h */
int flt32_get_val (flt32 x) {
	int field = (23 - 0) + 1;
	int mask = (1 << field) - 1;
	printBinary(x & mask);
	printf("\n");

  	return x & mask;
}

/** @todo Implement in flt32.c based on documentation contained in flt32.h */
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


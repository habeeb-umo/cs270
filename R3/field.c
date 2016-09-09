#include "field.h"

/** @file field.c
 *  @brief You will modify this file and implement five functions
 *  @details Your implementation of the functions defined in field.h.
 *  You may add other function if you find it helpful. 
 * <p>
 * @author <b>Your name</b> goes here
 */

/** @todo Implement in field.c based on documentation contained in field.h */
int getBit (int value, int position) {
    //requires right shift & modulo
	int mask = 1;
	value = value >> position;
	return value & mask;
}

/** @todo Implement in field.c based on documentation contained in field.h */
int setBit (int value, int position) {
	int mask = 1 << position;
    	return value | mask;
}

/** @todo Implement in field.c based on documentation contained in field.h */
int clearBit (int value, int position) {
	int mask = 1 << position;
   	 return ~(mask) & value;
}

/** @todo Implement in field.c based on documentation contained in field.h */
int getField (int value, int hi, int lo, bool isSigned) {
	printBinary(value);
	printf(" before\n");
	value = value >> lo;
	printBinary(value);
	printf(" after\n");
		
	int field = (hi - lo) + 1;
	int mask = (1 << field) - 1;
	value = value & mask;
	printBinary(value);
	printf(" after mask\n");
	if(isSigned && getBit(value, field) == 1){
	mask = ~mask;
	value = value | mask;
	}
   	return value;
}

/** @todo Implement in field.c based on documentation contained in field.h */
int setField (int oldValue, int hi, int lo, int newValue) {
    return 0;
}


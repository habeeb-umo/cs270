/*
 * testConv.c - simple driver to test methods of numconv.h.
 *
 * "Copyright (c) 2013-2016 by Fritz Sieker."
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose, without fee, and without written
 * agreement is hereby granted, provided that the above copyright notice
 * and the following two paragraphs appear in all copies of this software.
 *
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE TO ANY PARTY FOR DIRECT,
 * INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT
 * OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE AUTHOR
 * HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * THE AUTHOR SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS ON AN "AS IS"
 * BASIS, AND THE AUTHOR NO OBLIGATION TO PROVIDE MAINTENANCE, SUPPORT,
 * UPDATES, ENHANCEMENTS, OR MODIFICATIONS."
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "numconv.h"

/** @mainpage Number Conversion in C
 *  \htmlinclude "NUMCONV.html"
 */

/** @file: testConv.c
 *  @brief Driver to test functions of numConv.c (do not modify)
 *
 * @details This is a driver program to test the functions
 * defined in numConv.h and implemented in numConv.c. The program takes three
 * command line parameters and calls one of the methods, then
 * prints the results. To see how to use the program, execute
 * <code>./testConv</code> in a terminal window. This will print a usage
 * statement defining how to run the program. The 1st parameter of the
 * program is always a key defining which function to run.
 * The options are:
 * <ul>
 * <li><b>i2c</b> convert a number to a character digit</li>
 * <li><b>c2i</b> convert a character digit to its ordinal value</li>
 * <li><b>dnr</b> test the <code>divRem()</code> function</li>
 * <li><b>s2i</b> convert a string of characters to a number</li>
 * <li><b>i2s</b> print the digit(s) of a number specified by a string</li>
 * <li><b>s2d</b> convert a string of characters (possibly containing '.')
 * to a double</li>
 * </ul>
 * <p>
 * The 2nd parameter is always the radix you work in (2..36). The 3rd
 * parameter will be either a number (base 10) when you are converting an
 * number to a <b>character/characters</b>. It will be one/multiple characters
 * when converting to a <b>number</b>.
 * <p>
 * A sample execution might be: <code>testConv c2i 16 A</code>
 * <p>
 * All numbers are be entered as unsigned integers
 * <p>
 * @author Fritz Sieker
 */

/** Print a usage statement, then exit the program returning a non zero
 * value, the Linux convention indicating an error
 */
static void usage() {
  puts("Usage: testConv i2c radix number");
  puts("       testConv c2i radix digit");
  puts("       testConv dnr numerator divisor");
  puts("       testConv a2i radix strValue");
  puts("       testConv i2a radix number");
  puts("       testConv a2d radix strValue");
  puts("The radix and number parameters are always base 10 numbers.");
  exit(1);
}

/** Entry point of the program
 * @param argc count of arguments, will always be at least 1
 * @param argv array of parameters to program argv[0] is the name of
 * the program, so additional parameters will begin at index 1.
 * @return 0 the Linux convention for success.
 */
int main (int argc, char* argv[]) {
  if (argc != 4)
    usage();
  
  char* op    = argv[1];
  int   radix = atoi(argv[2]);

  if (strcmp(op, "c2i") == 0) {
    char c = argv[3][0];
    printf("char2int(%d, '%c') returns %d", radix, c, char2int(radix, c));
  }

  else if (strcmp(op, "i2c") == 0) {
    int n = atoi(argv[3]);
    printf("int2char(%d, %d) returns '%c'", radix, n, int2char(radix, n));
  }

  else if (strcmp(op, "dnr") == 0) {
    int num   = atoi(argv[2]);
    int denom = atoi(argv[3]);
    int quotient, remainder;

    printf("divRem(%d, %d) ", num, denom);
    divRem(num, denom, &quotient, &remainder);
    printf("quotient: %d remainder: %d", quotient, remainder);
  }

  else if (strcmp(op, "a2i") == 0) {
    const char* str = argv[3];
    printf("ascii2int(%d, \"%s\") returns %d", radix, str, ascii2int(radix, str));
  }

  else if (strcmp(op, "i2a") == 0) {
    int n = atoi(argv[3]);
    printf("int2ascii(%d, %d) returns \"", radix, n);
    int2ascii(radix, atoi(argv[3]));
    printf("\"");
  }

  else if (strcmp(op, "a2d") == 0) {
    const char* str = argv[3]; 
    printf("ascii2double(%d, \"%s\") returns %f", radix, str, ascii2double(radix, str));
  }
  
  else
    usage();
  
  printf("\n");
  return 0;
}


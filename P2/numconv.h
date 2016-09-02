#ifndef __NUMCONV_H__
#define __NUMCONV_H__

/*
 * numconv.h - simple functions to convert between internal/external
 * representations of numbers
 *
 * "Copyright (c) 2013-16 by Fritz Sieker."
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

/** @file numconv.h
 *  @brief Defines interface of numconv.c functions (do not modify)
 *  @details This file defines the interface to a C file numconv.c that
 *  you will complete. You will learn how to use the C language operators
 *  for address-of (<b>&amp;</b>), and dereferencing pointers <b>*</b>). 
 *  This will serve as a model when you implement the same functions in LC3
 *  assembly language.
 */

/** Return the character corresponding to the digit. 
 *  @param radix - the base you are working in (2-36)
 *  @param digit - a value in the range of <code>0 - (base-1)</code>
 *  @return - character '0' .. '9' or 'A'..'Z' if the value is legal. Otherwise
 *  return '?'
 */
char int2char (int radix, int digit);

/** Return the value corresponding to the character. 
 *  @param radix - the base you are working in (2-36)
 *  @param digit - character '0' .. '9' or 'A'..'Z' 'a' .. 'z'
 *  @return value in the range of <code>0 - (base-1)</code> if c is valid in
 *  the base. Otherwise return -1;
 */
int char2int (int radix, char digit);

/** Calculate both the quotient and remainder of a division and return the
 *  values via pointers. You may use the C operators for division (<b>/</b>)
 *  and modulus (<b>%</b>). However, you might want to write a loop to
 *  using repeated subtraction do the calculations to help you understand how
 *  you will implement this in LC3 assembly language (which has no operators
 *  for division or modulus).
 *  @param numerator - non-negative value for numerator
 *  @param divisor - a positive value to divide by
 *  @param quotient - a pointer to the location to store the result of division
 *  @param remainder - a pointer to the location to store the remainder
 */
void divRem (int numerator, int divisor, int* quotient, int* remainder);

/** Convert a string to an integer value
 *  @param radix - the base you are working in (2-36)
 *  @param str - the string
 *  @return the number represented by the string or -1 on error
 */
int ascii2int (int radix, const char *str);

/** Print a number in the specified base. Use the C call <code>putchar()</code>
 *  to print a single character obtained using <code>int2char()</code>.
 *  This corresponds to the <code>OUT</code> instruction of the LC3 OS. You may
 *  not use any other C I/O routine for printing. This function <b>MUST</b> be
 *  implemented recursively. <b>Your program can not use arrays or strings in C,
 *  even if you know about them.</b>
 *  @param radix - the base you are working in (2-36)
 *  @param value - the number to print
 */
void int2ascii (int radix, int value);

/** Convert the string to a double. <b>This function is for extra credit.</b>
 *  @param radix - the base you are working in (2-36)
 *  @param str - the string may contain the character '.' and the characters
 *  that follow it are the fractional portion of the number,
 *  @return the value as a double or -1.0 on error.
 */
double ascii2double (int radix, const char *str);

#endif

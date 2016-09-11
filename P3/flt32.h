#ifndef __FLT32_H__
#define __FLT32_H__

/*
 * flt32.h - header for simple floating point functions.
 *
 * "Copyright (c) 2013 by Fritz Sieker."
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

/** @file flt32.h
 *  @brief Defines interface of flt32.c functions (do not modify)
 *  @details This file defines the interface to a C file flt32.c that
 *  you will complete.  You will learn how to do floating point arithmetic
 *  <b>without using any <code>float</code> variables</b>. Rather you will
 *  perform the operations by using the sign, exponent, and digit fields
 *  as defined in the 
 *  <a href="http://en.wikipedia.org/wiki/IEEE_floating_point">IEEE floating
 *  Point Standard</a>.
 */

/** Whenever <code>flt32</code> is used, the value is an integer in the
 *  IEEE floating point 32 bit standard.
 */
#define flt32 int

/** Extract the sign of the argument
 *  @param x the integer containing a IEEE floating point value
 *  @return 0 if the value is 0 or positive, 1 if it is negative
 */
int flt32_get_sign (flt32 x);

/** Extract the exponent of the argument
 *  @param x the integer containing a IEEE floating point value
 *  @return the biased exponent of the argument
 */
int flt32_get_exp (flt32 x);

/** Extract the value of the argument
 *  @param x the integer containing a IEEE floating point value
 *  @return the <b>24</b> bits representing the mantissa with the
 *  implicit 1 on bit 23 (we call this the value). If x represents
 *  0.0, you should still add the implicit 1 to the mantissa
 */
int flt32_get_val (flt32 x);

/** Get the sign, exponent, and mantissa in a single call
 *  @param x the integer containing a IEEE floating point value
 *  @param sign pointer to location where the sign will be stored
 *  @param exp pointer to location where the exponent will be stored
 *  @param val pointer to location where the value will be stored
 */
void flt32_get_all(flt32 x, int* sign, int*exp, int* val);

/** Absolute value of the argument. This can be done with a simple bit
 *  manipulation operation. No conditionals are required.
 *  @param x the integer containing a IEEE floating point value
 *  @return the absolute value of the parameter
 */
flt32 flt32_abs (flt32 x);

/** Negate the argument. For example, if the argument represents 2.25,
 *  this function should return the IEEE bit pattern for -2.25.
 *  @param x the integer containing a IEEE floating point value
 *  @return the negation of the value. Note that the negation of 0.0
 *  is 0.0 (not -0.0)
 */
flt32 flt32_negate (flt32 x);

/** Add two floating point values
 *  @param x an integer containing a IEEE floating point value
 *  @param y an integer containing a IEEE floating point value
 *  @return x + y. Your code needs to account for a value of 0.0 in the
 *  operands or the result (or both), but no other special cases
 *  (e.g. infinities)
 */
flt32 flt32_add (flt32 x, flt32 y);

/** Subtract to floating point values
 *  @param x an integer containing a IEEE floating point value
 *  @param y an integer containing a IEEE floating point value
 *  @return x - y. Your code needs to account for a value of 0.0 in the
 *  operands or the result (or both), but no other special cases
 *  (e.g. infinities)
 */
flt32 flt32_sub (flt32 x, flt32 y);

#endif

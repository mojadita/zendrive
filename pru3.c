/* pru1.c --- test case for the first approach proposed.
 * Author: Luis Colorado <luiscoloradourcola@gmail.com>
 * Date: Thu Dec  7 15:23:52 EET 2017
 */

#include <float.h>
#include <stdio.h>
#include "pru.h"

#define N (1 << 23)
#define F(fmt) __FILE__":%d:%s:" fmt, __LINE__, __func__

float toFloat(int n)
{
	return (float) n / N;
} /* toFloat */

int toInt(float x)
{
	if (x == 0.0) return 0.0;
	/* return value is a constant value, no fp operation is made */
	if (x == N) return N - FLT_EPSILON;

	unsigned result = *(unsigned *)&x; /* mantissa */
	unsigned exp    = (result >> 23) & 0xff; /* the base 2 exponent */
	int is_neg = (result & 0x80000000) != 0; /* the sign */


	result &= 0x7fffff; /* isolate mantissa */
	result |= 0x800000; /* add msb */
	result >>= 127 - exp;
	if (is_neg) result = -result;

	return result;
} /* toInt */

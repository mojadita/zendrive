/* pru2.c --- test case for the second approach proposed.
 * Author: Luis Colorado <luiscoloradourcola@gmail.com>
 * Date: Thu Dec  7 10:27:48 EET 2017
 * This approach in the toFloat function doesn't involve
 * any floating point calculation, only bit shifts and
 * bitwise logic.
 */

#include <float.h>
#include <stdio.h>
#include "pru.h"

#define N (1 << 23)

#define SIZE(arry) (sizeof (arry) / sizeof (arry)[0])

float toFloat(int n)
{
	static const int masks[] = {
		0xffff00,
		0xff0000,
		0xf00000,
		0xc00000,
		0x800000,
	};
	static const int displs[] = {
		16, 8, 4, 2, 1,
	};
	const int is_neg = n < 0;
	int i, l = 0;

#if 1
	/* check for the two singular cases */
	switch(n) {
	case 0:		   return  0.0;
	case 0x800000: return -1.0;
	} /* switch */
#endif

	if (is_neg) n = -n; /* extract the sign */

	/* leftshift until we have the msg aligned with bit 23 */
	for (i = 0; i < SIZE(masks); i++) {
		l <<= 1;
		if (n & masks[i]) continue;
		n <<= displs[i];
		l |= 1;
	} /* for */

	/* l has the number of displacements done so far, n has
	 * the number displaced. */
	n &= 0x7fffff; /* clear the upper bits, above the mantissa. */
	n |= (127 - l) << 23; /* add the exponent, as for ieee754 compliance */
	n |= is_neg ? 0x80000000 : 0; /* ... and the sign */

	return *(float *)&n; /* return as a float. */
} /* toFloat */

int toInt(float x)
{
	if (x >= 1.0) x =  1.0 - FLT_EPSILON;
	if (x < -1.0) x = -1.0;
	return N * x;
} /* toInt */

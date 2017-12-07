/* pru1.c --- test case for the first approach proposed.
 * Author: Luis Colorado <luiscoloradourcola@gmail.com>
 * Date: Thu Dec  7 09:56:21 EET 2017
 */

#include <float.h>
#include "pru.h"

#define N (1 << 23)

float toFloat(int n)
{
	return (float) n / N;
} /* toFloat */

int toInt(float x)
{
	if (x >= 1.0) x =  1.0 - FLT_EPSILON;
	if (x < -1.0) x = -1.0;
	return N * x;
} /* toInt */

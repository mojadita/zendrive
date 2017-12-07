/* main.c --- main test program.
 * Author: Luis Colorado <luiscoloradourcola@gmail.com>
 * Date: Thu Dec  7 10:58:50 EET 2017
 */

#include <getopt.h>
#include <stdio.h>
#include "pru.h"

#define N (1 << 23)

#define FLAG_DEBUG	(1 << 0)

int main(int argc, char **argv)
{
	int n, opt;
	int flags = 0;

	while((opt = getopt(argc, argv, "v")) != EOF) {
		switch(opt) {
		case 'v': flags |= FLAG_DEBUG; break;
		} /* switch */
	} /* while */

	for (n = 0; n < N; n++) {
		float x1 = toFloat(n), x2 = toFloat(-n);
		int   n1 = toInt(x1),  n2 = toInt(x2);

		if (n != n1 || -n != n2) {
			fprintf(stderr,
				   "Oops: test failed\n"
				   "%8d => %12.7g => %8d\n"
				   "%8d => %12.7g => %8d\n",
				    n, x1, n1,
				   -n, x2, n2);
			break;
		} /* if */
		if (flags & FLAG_DEBUG) {
			printf("%8d => %12.7g => %8d\n"
				   "%8d => %12.7g => %8d\n",
				    n, x1, n1,
				   -n, x2, n2);
		} /* if */
	} /* for */
    if (n == N) {
        float x = toFloat(-n);
        int n1 = toInt(x);
        if (-n != n1) {
            fprintf(stderr,
                   "Oops: test failed\n"
                   "%8d => %12.7g => %8d\n",
                    n, x, n1);
            return 1;
        }
        if (flags & FLAG_DEBUG) {
            printf("%8d => %12.7g => %8d\n",
                    n, x, n1);
        } /* if */
    } /* if */
	return n < N;
} /* main */

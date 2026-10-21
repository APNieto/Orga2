#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

#include "../test-utils.h"
#include "ABI.h"

int main() {
	/* Acá pueden realizar sus propias pruebas */

	// assert(alternate_sum_4_using_c(8, 2, 5, 1) == 6);
	assert(alternate_sum_4_using_c(8, 2, 5, 1) == 10);

	// assert(alternate_sum_4_using_c_alternative(8, 2, 5, 1) == 6);
	assert(alternate_sum_4_using_c_alternative(8, 2, 5, 1) == 10);

	uint32_t r1 = alternate_sum_8(2, 3, 4, 5, 6, 7, 8, 1);  // == 4;
	printf("alternate_sum_8(2, 3, 4, 5, 6, 7, 8, 1) == %u\nShould be == 4.\n", r1);
	
	uint32_t *r2 = malloc(sizeof(uint32_t));
	product_2_f(r2, 2, 3.49);
	printf("product_2_f(2, 3.49) == %u\n", *r2);
	free(r2);
	

	// Minimalistic test version
	double *dp = malloc(sizeof(double));
	product_9_f(dp, 1, 1.1, 2, 2.2, 3, 3.3, 4, 4.4, 5, 5.5, 6, 6.6, 7, 7.7, 8, 8.8, 9, 9.9);
	printf("product_9_f() == %f\n", *dp);
	double result = 1 * 1.1 * 2 * 2.2 * 3 * 3.3 * 4 * 4.4 * 5 * 5.5 * 6 * 6.6 * 7 * 7.7 * 8 * 8.8 * 9 * 9.9;
	double result_float = (float)1 * (float)1.1 * (float)2 * (float)2.2 * (float)3 * (float)3.3 * (float)4 * (float)4.4 * (float)5 * (float)5.5 * (float)6 * (float)6.6 * (float)7 * (float)7.7 * (float)8 * (float)8.8 * (float)9 * (float)9.9;
	printf("Should be     == %f\n", result);
	printf("float version == %f\n", result_float);
	free(dp);
	
	
	// // Real version
	// product_9_f(dp, 2, 3.14);
	// printf("product_9_f() == %f\n", *dp);
	// double result = 121645100.41;
	// printf("Should be == %f\n", result);
	// free(dp);

	return 0;
}

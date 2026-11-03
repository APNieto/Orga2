#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

#include "../test-utils.h"
#include "Memoria.h"

int main() {
	/* Acá pueden realizar sus propias pruebas */

// 	strCmp
	char *a = "pimba";
	char *b = "pimb";
	printf("'pimba' vs. 'pimb': should be 1\n");
	printf("'pimba' vs. 'pimb': %d\n", strCmp(a, b));
	
	a = "a";
	b = "pimb";
	printf("'a' vs. 'pimb': should be -1\n");
	printf("'a' vs. 'pimb': %d\n", strCmp(a, b));
	
	a = "abc10";
	b = "abc20";
	printf("'abc10' vs. 'abc20': should be -1\n");
	printf("'abc10' vs. 'abc20': %d\n", strCmp(a, b));

	a = "abc098";
	b = "ad";
	printf("'abc098' vs. 'ad': should be -1\n");
	printf("'abc098' vs. 'ad': %d\n", strCmp(a, b));

	a = "abc";
	b = "9";
	printf("'abc' vs. '9': should be 1\n");
	printf("'abc' vs. '9': %d\n", strCmp(a, b));






	return 0;
}

// ToDo:
// 1. try asserts
// 2. examine with gdb

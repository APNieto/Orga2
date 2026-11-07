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
	printf("//	strCmp\n");
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
	printf("\n---------------------------------\n\n");
	
	
	

	//	strLen
	printf("//	strLen\n");
	char *s1 = "pimbar";
	char *s2 = "";
	char *s3 = "pimbero";
	
	printf("length 'pimbar' == %u\nShould be == 6.\n", strLen(s1));
	printf("length '' == %u\nShould be == 0.\n", strLen(s2));
	printf("length 'pimbaro' == %u\nShould be == 7.\n", strLen(s3));
	printf("\n---------------------------------\n\n");
	
	
	
	
	//	strDeleted
	printf("//	strDeleted\n");
	char *s4 = malloc(sizeof(char) * 9);
	strcpy(s4, "pimbucha");
	
	printf("string at s4 == %s\nShould be == 'pimbucha'.\n", s4);
	strDelete(s4);
	printf("string at s4 after strDelete(s4) == %s\nShould be undefined.\n", s4);
	printf("\n---------------------------------\n\n");
	
	
	
	//	strClone
	printf("//	strClone\n");
	char *s5 = "pimbubina";
	
	printf("string at s5 == %s\nShould be == 'pimbubina'.\n", s5);
	char *s6 = (char *)strClone(s5);
	printf("string at s6 after < char *s6 = strClone(s5) > : %s\n", s6);
	printf("\n---------------------------------\n\n");
	free(s6);
	
	
	return 0;
}



// ToDo:
// 1. try asserts
// 2. examine with gdb
// 3. errores de valgrind

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

#include "../test-utils.h"
#include "Estructuras.h"

#define LONGITUD_ARR_n1_a 3
#define LONGITUD_ARR_n2_a 4
#define LONGITUD_ARR_n3_a 6

int main() {
	/* Acá pueden realizar sus propias pruebas */

	uint32_t n2_a[LONGITUD_ARR_n2_a] = { 5, 6, 7, 8 };
	nodo_t n2 = { .next = NULL, .categoria = 2, .arreglo = n2_a, .longitud = LONGITUD_ARR_n2_a };
	uint32_t n1_a[LONGITUD_ARR_n1_a] = { 2, 3, 4 };
	nodo_t n1 = { .next = &n2, .categoria = 2, .arreglo = n1_a, .longitud = LONGITUD_ARR_n1_a };
	lista_t lista = { .head = &n1 };
	
	uint32_t r1 = sumatoria_de_elementos(&lista);
	printf("Sumatoria elementos en lista de arrays: %u\n", r1);
	
	uint32_t r2 = cantidad_total_de_elementos(&lista);
	printf("Cantidad total de elementos en lista de arrays: %u\n", r2);
	
	
	
	uint32_t n3_a[LONGITUD_ARR_n3_a] = { 5, 6, 7, 8, 2, 1};
	packed_nodo_t np2 = { .next = NULL, .categoria = 3, .arreglo = n3_a, .longitud = LONGITUD_ARR_n3_a };
	packed_nodo_t np1 = { .next = &np2, .categoria = 3, .arreglo = n1_a, .longitud = LONGITUD_ARR_n1_a };
	packed_lista_t lista_p = { .head = &np1 };
	
	uint32_t r3 = cantidad_total_de_elementos_packed(&lista_p);
	printf("Cantidad total de elementos en lista de arrays packed: %u\n", r3);

	return 0;
}

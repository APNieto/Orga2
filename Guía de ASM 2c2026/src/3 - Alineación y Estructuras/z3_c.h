#include <stdint.h>


typedef struct alumno {
    char *nombre;
    char comision;
    int dni;
} alumno;


extern void print_names_alumnos(alumno *a, uint32_t size, uint32_t size_alumno);
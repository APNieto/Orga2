// Untersuchung zur Übergabe von eigenständigen Structs als Argumente

#include <stdio.h>

typedef struct alumno {
    char *nombre;
    char comision;
    int dni;
} alumno;

// void print_names_alumnos(alumno a1) {
//     printf("Name: '%s'.\n", a1.nombre);
// }

int main() {

    alumno a1;
    a1.nombre = "pimbati";
    print_names_alumnos(a1);    

}
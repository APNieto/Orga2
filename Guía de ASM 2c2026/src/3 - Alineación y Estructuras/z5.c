// Untersuchung zur Übergabe von eigenständigen Structs als Argumente

#include <stdio.h>

typedef struct alumno {
    char *nombre;
    char comision;
    int dni;
    long long1;
} alumno;

// void print_names_alumnos(alumno a1) {
//     printf("Name: '%s'.\n", a1.nombre);
//     printf("Comision: '%c'.\n", a1.comision);
//     printf("DNI: '%d'.\n", a1.dni);
//     printf("long1: '%d'.\n", a1.long1);
// }

int main() {

    alumno a1;
    a1.nombre = "pimbati890";
    a1.comision = 'A';
    a1.dni = 30303030;
    a1.long1 = 1000;
    print_names_alumnos(a1);

}


// Fazit: bis zu 2 eightbytes werden mittels Register übergegeben;
// falls mehr, dann landet der gesamte Struct in Argumentenbereich des Callers
// Ausgabe der Namenattribute in einem Array von Structs

#include "z3_c.h"

int main() {

    alumno a1;
    a1.nombre = "pimba";
    alumno a2;
    a2.nombre = "rola";
    alumno a3;
    a3.nombre = "mola";

    alumno alumnos[3] = {a1, a2, a3};

    print_names_alumnos(alumnos, sizeof(alumnos) / sizeof(alumno));
    

}


// Compiled with lines:

// gcc -g -c z3_c.c -o z3_c.o
// nasm -f elf64 -g z3_asm.asm -o z3_asm.o

// gcc -g -no-pie z3_c.o z3_asm.o -o z3

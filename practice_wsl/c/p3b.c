// Ejercicio 12
// Definir una funci´on crearPersona que reciba un nombre y una edad, y devuelva un
// puntero a una estructura persona_t que contenga esos datos. La funci´on debe reservar
// memoria din´amica para la estructura y devolver el puntero. Luego, en la funci´on main,
// crear una persona y liberar la memoria reservada. El string que se pasa por par´ametro
// debe ser copiado a la estructura.

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char nombre[128];
    short edad;
} persona_t;

persona_t *crear_persona(const char *nombre, short edad) {
    persona_t *persona = malloc(sizeof(persona_t));
    if (persona == NULL) {
        printf("malloc returned NULL pointer.\n");
        return NULL;
    }
    strcpy(persona->nombre, nombre);
    persona->edad = edad;   
    return persona;
}

int main(){

    persona_t *p1;
    char input_nombre[128];
    short input_edad;

    printf("Enter name: ");
    scanf("%s", input_nombre);
    printf("Enter age: ");
    scanf("%hd", &input_edad);
    p1 = crear_persona(input_nombre, input_edad);

    printf("Persona creada.\n");
    printf("Nombre: %s\n", p1->nombre);
    printf("Edad: %hd\n", p1->edad);

    free(p1);
    
}



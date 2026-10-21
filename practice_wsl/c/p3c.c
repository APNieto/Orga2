#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// Ejerccio 13
// Definir una funci´on eliminarPersona que reciba un puntero a una estructura persona t
// y libere la memoria reservada para la estructura.

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

persona_t *eliminar_persona(persona_t *persona){
    free(persona);
    return NULL;
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
    
    printf("Persona eliminada.\n");
    p1 = eliminar_persona(p1);
    
}


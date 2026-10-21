// Ejercicio debugging, pg.44

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef enum {
  MENTA,
  DDL,
  OREO,
  LIMON
} gustoDeHelado_t;

char *gustosDeHelado[4] = {"menta", "dulce de leche", "oreo", "limón"};

typedef struct heladoOfrecido_t {
  uint32_t precio;
  gustoDeHelado_t gusto;
} heladoOfrecido_t;

heladoOfrecido_t heladoOfrecido_DDL = {.precio = 5, .gusto = DDL};

typedef struct usuario_t{
  char nombre[5];
  int saldo;
  uint8_t habilitado;
  gustoDeHelado_t gustoDeHeladoFavorito;
} usuario_t;

void habilitarUsuario(usuario_t *usuario){
  usuario->habilitado = 1;
  for (int i = 0; i < 4; i++){
    usuario->nombre[i] = '\0';
  }
  usuario->saldo = 0;
}

void aumentarSaldo(int saldoDeUsuario, int cantidad) {    // POSIBLE BUG
  saldoDeUsuario += cantidad;
} 

void comprarHelado(usuario_t *usuario, heladoOfrecido_t **helado){
  if(usuario->saldo >= 5) {  
    usuario->saldo -= 5;     // POSIBLE BUG
    *helado = &heladoOfrecido_DDL;
  }
  else {
    printf("El usuario no tiene saldo suficiente.\n");
  }
}

int main(void){

  usuario_t *nuevoUsuario = malloc(sizeof(usuario_t));
  habilitarUsuario(nuevoUsuario);

  if (nuevoUsuario->habilitado){
    printf("Usuario habilitado con éxito. \n");
    int cargaInicial = 10;
    aumentarSaldo(nuevoUsuario->saldo, cargaInicial);

    heladoOfrecido_t *heladoOfrecido = NULL;
    comprarHelado(nuevoUsuario, &heladoOfrecido);
    nuevoUsuario->gustoDeHeladoFavorito = heladoOfrecido->gusto;

    printf("Usuario creado con éxito. \n");
    printf("Su saldo es de %d pesos y su gusto favorito es %s.\n", 
      nuevoUsuario->saldo,
      gustosDeHelado[nuevoUsuario->gustoDeHeladoFavorito]
    );
  } else {
    printf("Error al habilitar usuario %d.\n", nuevoUsuario->habilitado);
  }

  free(nuevoUsuario);

}

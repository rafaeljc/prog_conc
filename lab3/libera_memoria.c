#include <stdlib.h>

#include "matriz.h"

extern Matriz matriz_1;
extern Matriz matriz_2;
extern Matriz matriz_saida;

void LiberaMemoria() {
  free(matriz_1.elementos);
  free(matriz_2.elementos);
  free(matriz_saida.elementos);
}

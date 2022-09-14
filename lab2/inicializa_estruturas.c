#include <stdio.h>

#include "estruturas.h"

extern Matriz matriz_1;
extern Matriz matriz_2;
extern Matriz matriz_saida;

void InicializaEstruturas() {
  LeMatriz(&matriz_1);
  LeMatriz(&matriz_2);
  InstanciaMatriz(&matriz_saida, matriz_1.num_linhas, matriz_2.num_colunas);
}

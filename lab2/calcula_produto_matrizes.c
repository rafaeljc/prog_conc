#include <stdio.h>
#include <stdlib.h>

#include "estruturas.h"

extern Matriz matriz_1;
extern Matriz matriz_2;
extern Matriz matriz_saida;

void CalculaProdutoMatrizes() {
  // checando condição de existência
  if (matriz_1.num_colunas != matriz_2.num_linhas) {
    fprintf(stderr, "O número de colunas da matriz 1 precisa ser igual ao número de linhas da matriz 2!\n");
    exit(4);
  }

  for (int i = 0; i < matriz_saida.num_linhas; i++) {
    for (int j = 0; j < matriz_saida.num_colunas; j++) {
      // calcula o produto interno
      float soma = 0.0;
      for (int k = 0; k < matriz_1.num_colunas; k++) {
        soma += matriz_1.elementos[i*matriz_1.num_colunas + k] * matriz_2.elementos[k*matriz_2.num_colunas + j];
      }
      matriz_saida.elementos[i*matriz_saida.num_colunas + j] = soma;
    }
  }
} 

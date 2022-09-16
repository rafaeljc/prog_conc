#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "matriz.h"

extern Matriz matriz_1;
extern Matriz matriz_2;
extern Matriz matriz_saida;
extern int num_threads;

void* CalculaProdutoMatrizes(void* arg) {  
  // checando condição de existência
  if (matriz_1.num_colunas != matriz_2.num_linhas) {
    fprintf(stderr, "O número de colunas da matriz 1 precisa ser igual ao número de linhas da matriz 2!\n");
    exit(4);
  }

  int thread_id = *((int*) arg);
  thread_id--; // ajustando porque thread_id começa em '1'
  for (int i = thread_id; i < matriz_saida.num_linhas; i += num_threads) {
    for (int j = 0; j < matriz_saida.num_colunas; j++) {
      // calcula o produto interno
      float soma = 0.0;
      for (int k = 0; k < matriz_1.num_colunas; k++) {
        soma += matriz_1.elementos[i*matriz_1.num_colunas + k] * matriz_2.elementos[k*matriz_2.num_colunas + j];
      }
      matriz_saida.elementos[i*matriz_saida.num_colunas + j] = soma;
    }
  }
  pthread_exit(NULL);
} 

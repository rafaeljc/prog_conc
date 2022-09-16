#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "calcula_produto_matrizes.h"

extern int num_threads;

void CriaThreads() {
  pthread_t lista_threads[num_threads];
  int lista_ids[num_threads];
  // cria threads
  for (int i = 0; i < num_threads; i++) {
    lista_ids[i] = i + 1;
    if (pthread_create(&lista_threads[i], NULL, CalculaProdutoMatrizes, (void*) &lista_ids[i])) {
      fprintf(stderr, "Não foi possível criar a thread %d!\n", lista_ids[i]);
      exit(-2);
    }    
  }
  // aguarda execução das threads
  for (int i = 0; i < num_threads; i++) {
    if (pthread_join(lista_threads[i], NULL)) {
      fprintf(stderr, "Erro ao aguardar execução da thread %d!\n", lista_ids[i]);
      exit(-3);
    }
  }
}

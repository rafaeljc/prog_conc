#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void TrataArgumentosEntrada(int argc, char* argv[], int num_threads[], pthread_t** threads, int** threads_ids) {
  int total_tarefas = num_threads[0];

  switch (argc) {
    case 4:
      total_tarefas = 0;  // inicia o contador de tarefas
      for (int i = 1; i <= 3; i++) {
        num_threads[i] = atoi(argv[i]);
        total_tarefas += num_threads[i];
      }
      num_threads[0] = total_tarefas;

    case 1:
      *threads = (pthread_t*) malloc(sizeof(pthread_t) * total_tarefas);
      if (!*threads) {
        fprintf(stderr, "ERRO: malloc -> threads[%d]\n", total_tarefas);
        exit(-1);
      }
      *threads_ids = (int*) malloc(sizeof(int) * total_tarefas);
      if (!*threads_ids) {
        fprintf(stderr, "ERRO: malloc -> threads_ids[%d]\n", total_tarefas);
        exit(-1);
      }
      break;

    default:
      fprintf(stderr, "Argumento inválido!\n");
      fprintf(stderr, "Uso: %s [<num Tarefa1> <num Tarefa2> <num Tarefa3>]\n", argv[0]);
      exit(1);
  }
}

void LiberaMemoria(pthread_t* threads, int* threads_ids) {
  free(threads);
  free(threads_ids);
}

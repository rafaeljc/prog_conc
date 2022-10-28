#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

extern char* buffer;

void TrataArgumentosEntrada(int argc, char* argv[], int num_threads[], pthread_t** threads, int** threads_ids) {
  int total_threads = num_threads[0];

  switch (argc) {
    case 3:
      total_threads = 0;  // inicia o contador de threads
      for (int i = 1; i <= 2; i++) {
        num_threads[i] = atoi(argv[i]);
        total_threads += num_threads[i];
      }
      num_threads[0] = total_threads;

    case 1:
      *threads = (pthread_t*) malloc(sizeof(pthread_t) * total_threads);
      if (!*threads) {
        fprintf(stderr, "ERRO: malloc -> threads[%d]\n", total_threads);
        exit(-1);
      }
      *threads_ids = (int*) malloc(sizeof(int) * total_threads);
      if (!*threads_ids) {
        fprintf(stderr, "ERRO: malloc -> threads_ids[%d]\n", total_threads);
        exit(-1);
      }
      break;

    default:
      fprintf(stderr, "Argumento inválido!\n");
      fprintf(stderr, "Uso: %s [<num produtores> <num consumidores>]\n", argv[0]);
      exit(1);
  }
}

void LiberaMemoria(pthread_t* threads, int* threads_ids) {
  free(threads);
  free(threads_ids);
  free(buffer);
}

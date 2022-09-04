#include "estruturas.h"

void *AumentaValor(void *arg) {
  ThreadArgs *args = (ThreadArgs *) arg;
  Vetor *vetor = args->vetor;
  int thread_id = args->thread_id;
  int num_threads = args->num_threads;
  // Utiliza o id da thread que chamou a função para
  // determinar os elementos do vetor que serão modificados
  for (int i = thread_id; i < vetor->tamanho; i += num_threads)
    vetor->elementos[i] *= 1.10;
  pthread_exit(NULL);    
}

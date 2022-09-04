#include <stdio.h>
#include <stdlib.h>

#include "estruturas.h"
#include "aumenta_valor.h"

void CriaThreads(Vetor *vetor, ListaDeThreads *lista_threads) {
  ThreadArgs *arg;
  for (int t_id = 0; t_id < lista_threads->tamanho; t_id++) {
    arg = (ThreadArgs *) malloc(sizeof(ThreadArgs));
    if (arg == NULL) {
      printf("ERRO: CriaThreads -> malloc()\n");
      exit(-1);
    }
    arg->vetor = vetor;
    arg->thread_id = t_id;
    arg->num_threads = lista_threads->tamanho;
    pthread_create(&(lista_threads->threads[t_id]), NULL, AumentaValor, (void *) arg);
  }
}

#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#include <pthread.h>

typedef struct {
  float *elementos;
  int tamanho;
} Vetor;
void InstanciaVetor(Vetor *vetor, int tamanho);

typedef struct {
  pthread_t *threads;
  int tamanho;
} ListaDeThreads;
void InstanciaListaDeThreads(ListaDeThreads *lista, int tamanho);

typedef struct {
  Vetor *vetor;
  int thread_id;
  int num_threads;
} ThreadArgs;

#endif // ESTRUTURAS_H

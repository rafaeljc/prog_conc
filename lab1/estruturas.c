#include <stdio.h>
#include <stdlib.h>

#include "estruturas.h"

void InstanciaVetor(Vetor *vetor, int tamanho) {
  vetor->tamanho = tamanho;
  vetor->elementos = (float *) malloc(tamanho*sizeof(float));
  if (vetor->elementos == NULL) {
    printf("ERRO: InstanciaVetor -> malloc()\n");
    exit(-1);
  }
}

void InstanciaListaDeThreads(ListaDeThreads *lista, int tamanho) {
  lista->tamanho = tamanho;
  lista->threads = (pthread_t *) malloc(tamanho*sizeof(pthread_t));
  if (lista->threads == NULL) {
    printf("ERRO: InstanciaListaDeThreads -> malloc()\n");
    exit(-1);
  }
}

// Programação Concorrente 2022.2
// Laboratório 1
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 2
#define TAM_VETOR 10000

typedef struct {
  float *vetor;
  int thread_id;
} ThreadArgs;

void *AumentaValor(void *arg) {
  ThreadArgs *args = (ThreadArgs *) arg;
  // Utiliza o id da thread que chamou a função para
  // determinar os elementos do vetor que serão modificados
  for (int i = args->thread_id; i < TAM_VETOR; i += NUM_THREADS)
    args->vetor[i] *= 1.10;
  pthread_exit(NULL);    
}

void InicializaVetor(float vetor[]) {
  for (int i = 0; i < TAM_VETOR; i++)
    vetor[i] = (float) i + 1;
}

void CriaThreads(float vetor[], pthread_t lista_threads[]) {
  ThreadArgs *arg;
  for (int t_id = 0; t_id < NUM_THREADS; t_id++) {
    arg = (ThreadArgs *) malloc(sizeof(ThreadArgs));
    if (arg == NULL) {
      printf("ERRO: CriaThreads -> malloc()\n");
      exit(-1);
    }
    arg->vetor = vetor;
    arg->thread_id = t_id;
    pthread_create(&lista_threads[t_id], NULL, AumentaValor, (void *) arg);
  }
}

void AguardaExecucaoThreads(pthread_t lista_threads[]) {
  for (int t_id = 0; t_id < NUM_THREADS; t_id++)
    pthread_join(lista_threads[t_id], NULL);
}

void VerificaValores(float vetor[]) {
  float n;
  for (int i = 0; i < TAM_VETOR; i++) {
    n = (i + 1)*1.10;
    if (vetor[i] != n) {
      printf("Falhou!\n");
      return;
    }    
  }
  printf("Sucesso!\n");
}

int main(int argc, char *argv[]) {
  float vetor[TAM_VETOR];
  pthread_t lista_threads[NUM_THREADS];

  InicializaVetor(vetor);
  CriaThreads(vetor, lista_threads);
  AguardaExecucaoThreads(lista_threads);
  VerificaValores(vetor);

  return 0;
}

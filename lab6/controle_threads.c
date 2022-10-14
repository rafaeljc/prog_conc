#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#include "tarefas.h"

// variáveis para sincronização
pthread_mutex_t mutex;
pthread_cond_t cond_leitura;
pthread_cond_t cond_escrita;
int threads_lendo = 0;
bool thread_escrevendo = false;

void InicioLeitura(int id) {
  pthread_mutex_lock(&mutex);

  printf(" L(%d): Quer ler.\n", id);
  while (thread_escrevendo) {
    printf(" L(%d): Bloqueou!\n", id);
    pthread_cond_wait(&cond_leitura, &mutex);
    printf(" L(%d): Desbloqueou!\n", id);
  }
  threads_lendo++;

  pthread_mutex_unlock(&mutex);
}

void FimLeitura(int id) {
  pthread_mutex_lock(&mutex);

  threads_lendo--;
  printf(" L(%d): Finalizou a leitura.\n", id);  
  if (!threads_lendo) {
    pthread_cond_signal(&cond_escrita);
  }    

  pthread_mutex_unlock(&mutex);
}

void InicioEscrita(int id) {
  pthread_mutex_lock(&mutex);

  printf(" E(%d): Quer escrever.\n", id);
  while (threads_lendo || thread_escrevendo) {
    printf(" E(%d): Bloqueou!\n", id);
    pthread_cond_wait(&cond_escrita, &mutex);
    printf(" E(%d): Desbloqueou!\n", id);
  }
  thread_escrevendo = true;

  pthread_mutex_unlock(&mutex);
}

void FimEscrita(int id) {
  pthread_mutex_lock(&mutex);

  thread_escrevendo = false;
  printf(" E(%d): Finalizou a escrita.\n", id);  
  pthread_cond_signal(&cond_escrita);
  pthread_cond_broadcast(&cond_leitura);

  pthread_mutex_unlock(&mutex);
}

void InicializaVariaveisControle(void) {
  pthread_mutex_init(&mutex, NULL);
  pthread_cond_init(&cond_leitura, NULL);
  pthread_cond_init(&cond_escrita, NULL);
}

void LiberaVariaveisControle(void) {
  pthread_mutex_destroy(&mutex);
  pthread_cond_destroy(&cond_leitura);
  pthread_cond_destroy(&cond_escrita);
}

void InicializaThreads(int num_threads[], pthread_t threads[], int threads_ids[]) {
  // cria as threads relacionadas à Tarefa1
  int i = 0;
  for (; i < num_threads[1]; i++) {
    threads_ids[i] = i;
    if (pthread_create(&threads[i], NULL, Tarefa1, (void*) &threads_ids[i])) {
      fprintf(stderr, "Não foi possível criar a thread T1(%d)!\n", threads_ids[i]);
      exit(-2);
    }
  }

  // cria as threads relacionadas à Tarefa2
  int limite = i + num_threads[2];
  for (; i < limite; i++) {
    threads_ids[i] = i;
    if (pthread_create(&threads[i], NULL, Tarefa2, (void*) &threads_ids[i])) {
      fprintf(stderr, "Não foi possível criar a thread T2(%d)!\n", threads_ids[i]);
      exit(-2);
    }
  }

  // cria as threads relacionadas à Tarefa3
  limite = i + num_threads[3];
  for (; i < limite; i++) {
    threads_ids[i] = i;
    if (pthread_create(&threads[i], NULL, Tarefa3, (void*) &threads_ids[i])) {
      fprintf(stderr, "Não foi possível criar a thread T3(%d)!\n", threads_ids[i]);
      exit(-2);
    }
  }
}

void AguardaExecucaoThreads(pthread_t threads[], int total_threads) {
  for (int i = 0; i < total_threads; i++) {
    if (pthread_join(threads[i], NULL)) {
      fprintf(stderr, "Erro ao aguardar execução da thread %d!\n", i);
      exit(-3);
    }
  }
  puts("--- TAREFAS CONCLUÍDAS ---");
}

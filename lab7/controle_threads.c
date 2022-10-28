#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

#include "tarefas.h"

// variáveis para sincronização
sem_t mutex_cons;
sem_t slot_cheio;
sem_t buffer_vazio;
char* buffer;
const int tam_buffer = 10;

void Insere(char* str, int id) {
  sem_wait(&buffer_vazio);
  // copia todas as letras pro buffer
  strncpy(buffer, str, tam_buffer);
  printf("P(%d): Inseriu %s no buffer\n", id, str);
  printf("[%s]\n", buffer);
  // faz incrementos em slot_cheio
  // liberando o consumo
  for (int i = 0; i < tam_buffer; i++) {
    sem_post(&slot_cheio);
  }
}

char Retira(int id) {
  static int i = 0;
  char c;

  sem_wait(&slot_cheio);

  sem_wait(&mutex_cons);
  c = buffer[i];
  buffer[i] = ' ';  // sinaliza posição vazia
  printf("C(%d): Retirou %c do buffer\n", id, c);
  printf("[%s]\n", buffer);
  // se foi o último slot cheio
  // avisa que ficou vazio
  if (i == (tam_buffer - 1)) {
    sem_post(&buffer_vazio);
  }
  i = (i + 1) % tam_buffer;

  sem_post(&mutex_cons);   

  return c;
}

void InicializaBuffer(void) {
  // aloca uma posição a mais por causa do caractere '\0'
  buffer = (char*) malloc(sizeof(char) * (tam_buffer + 1));
  if (!buffer) {
    fprintf(stderr, "ERRO: InicializaBuffer() -> malloc()\n");
    exit(-1);
  }
  // inicializa o buffer vazio
  for (int i = 0; i < tam_buffer; i++) {
    buffer[i] = ' ';
  }
  // indica o final do buffer
  buffer[tam_buffer] = '\0';
  printf("[%s]\n", buffer);
}

void InicializaVariaveisControle(void) {
  sem_init(&mutex_cons, 0, 1);
  sem_init(&slot_cheio, 0, 0);
  sem_init(&buffer_vazio, 0, 1);
}

void DestroiVariaveisControle(void) {
  sem_destroy(&mutex_cons);
  sem_destroy(&slot_cheio);
  sem_destroy(&buffer_vazio);
}

void InicializaThreads(int num_threads[], pthread_t threads[], int threads_ids[]) {
  // cria as threads de produtores
  int i = 0;
  for (; i < num_threads[1]; i++) {
    threads_ids[i] = i;
    if (pthread_create(&threads[i], NULL, produtor, (void*) &threads_ids[i])) {
      fprintf(stderr, "Não foi possível criar o produtor(%d)!\n", threads_ids[i]);
      exit(-2);
    }
  }

  // cria as threads de consumidores
  int limite = i + num_threads[2];
  for (; i < limite; i++) {
    threads_ids[i] = i;
    if (pthread_create(&threads[i], NULL, consumidor, (void*) &threads_ids[i])) {
      fprintf(stderr, "Não foi possível criar o consumidor(%d)!\n", threads_ids[i]);
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
  puts("--- THREADS FINALIZADAS ---");
}

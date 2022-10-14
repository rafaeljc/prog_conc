#include <stdio.h>
#include <pthread.h>

#include "controle_threads.h"

// variável de acesso comum às tarefas
int base_dados = 0;

int EhImpar(int num) {
  return num % 2;
}

void* Tarefa1(void* arg) {
  int id = *((int*) arg);
  printf("T1(%d): Começou.\n", id);

  InicioEscrita(id);
  base_dados++;
  FimEscrita(id);

  printf("T1(%d): Terminou.\n", id);
  pthread_exit(NULL);
}

void* Tarefa2(void* arg) {
  int id = *((int*) arg);
  printf("T2(%d): Começou.\n", id);

  InicioLeitura(id);
  if (EhImpar(base_dados)) {
    printf("T2(%d): %d é um valor ímpar.\n", id, base_dados);
  } else {
    printf("T2(%d): %d é um valor par.\n", id, base_dados);
  }
  FimLeitura(id);

  printf("T2(%d): Terminou.\n", id);
  pthread_exit(NULL);
}

void* Tarefa3(void* arg) {
  int id = *((int*) arg);
  printf("T3(%d): Começou.\n", id);

  InicioLeitura(id);
  printf("T3(%d): O valor é: %d\n", id, base_dados);
  FimLeitura(id);

  // faz qualquer coisa
  for (int i = 0; i < 1000; i++);

  InicioEscrita(id);
  // atribui o identificador da thread
  base_dados = id;
  FimEscrita(id);

  printf("T3(%d): Terminou.\n", id);
  pthread_exit(NULL);
}

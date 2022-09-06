//  Programação Concorrente 2022.2
//  Laboratório 1
//
//  Compilando:
// gcc -c *.c
// gcc *.o -Wall -lpthread
//  Uso:
// ./a.out [número de threads]
// Obs: Caso nenhum valor for passado, 2 threads serão criadas
#include <stdio.h>
#include <stdlib.h>

#include "estruturas.h"
#include "aguarda_execucao_threads.h"
#include "cria_threads.h"
#include "inicializa_vetor.h"
#include "verifica_valores.h"

#define NUM_THREADS 2
#define TAM_VETOR 10000

int main(int argc, char *argv[]) {
  int num_threads = NUM_THREADS;
  if (argc == 2) {
    num_threads = atoi(argv[1]);
  }

  Vetor vetor;
  InstanciaVetor(&vetor, TAM_VETOR);
  ListaDeThreads lista_threads;
  InstanciaListaDeThreads(&lista_threads, num_threads);

  printf("Número de threads: %d\n", num_threads);
  InicializaVetor(&vetor);
  CriaThreads(&vetor, &lista_threads);
  AguardaExecucaoThreads(&lista_threads);
  VerificaValores(&vetor);

  return 0;
}

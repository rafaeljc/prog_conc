// Programação Concorrente 2022.2
// Laboratório 1
#include "estruturas.h"
#include "aguarda_execucao_threads.h"
#include "aumenta_valor.h"
#include "cria_threads.h"
#include "inicializa_vetor.h"
#include "verifica_valores.h"

#define NUM_THREADS 2
#define TAM_VETOR 10000

int main(int argc, char *argv[]) {
  Vetor vetor;
  InstanciaVetor(&vetor, TAM_VETOR);
  ListaDeThreads lista_threads;
  InstanciaListaDeThreads(&lista_threads, NUM_THREADS);

  InicializaVetor(&vetor);
  CriaThreads(&vetor, &lista_threads);
  AguardaExecucaoThreads(&lista_threads);
  VerificaValores(&vetor);

  return 0;
}

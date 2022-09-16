/* Programação Concorrente 2022.2
   Laboratório 3
*/
#include <stdio.h>

#include "cria_threads.h"
#include "inicializa_estruturas.h"
#include "libera_memoria.h"
#include "matriz.h"
#include "timer.h"
#include "trata_argumentos_entrada.h"

Matriz matriz_1;
Matriz matriz_2;
Matriz matriz_saida;
int num_threads = 2; // default

int main(int argc, char* argv[]) {
  double inicio, fim;
  double lista_delta[3];

  // Inicialização
  GET_TIME(inicio);
  TrataArgumentosEntrada(argc, argv);
  InicializaEstruturas();
  GET_TIME(fim);
  lista_delta[0] = fim - inicio;

  // Processamento
  GET_TIME(inicio);
  CriaThreads();
  GET_TIME(fim);
  lista_delta[1] = fim - inicio;

  // Finalização
  GET_TIME(inicio);
  EscreveMatriz(&matriz_saida);
  LiberaMemoria();
  GET_TIME(fim);
  lista_delta[2] = fim - inicio;
  puts("Pronto!");

  double total = lista_delta[0] + lista_delta[1] + lista_delta[2];
  puts("--- RESUMO");
  printf("Número de threads: \t%d\n", num_threads);
  printf("Matriz (saída): \t%d x %d\n", matriz_saida.num_linhas, matriz_saida.num_colunas);
  puts("- Tempo de Execução");
  printf("Inicialização: \t\t%lf\n", lista_delta[0]);
  printf("Processamento: \t\t%lf\n", lista_delta[1]);
  printf("Finalização: \t\t%lf\n", lista_delta[2]);
  printf("Total: \t\t\t%lf\n", total);

  return 0;
}

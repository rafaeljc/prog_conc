/* Programação Concorrente 2022.2
   Laboratório 2
*/
#include <stdio.h>

#include "calcula_produto_matrizes.h"
#include "estruturas.h"
#include "inicializa_estruturas.h"
#include "libera_memoria.h"
#include "timer.h"
#include "trata_argumentos_entrada.h"

Matriz matriz_1;
Matriz matriz_2;
Matriz matriz_saida;

int main(int argc, char* argv[]) {
  double inicio, fim;
  double lista_delta[3];

  puts("Inicializando...");
  GET_TIME(inicio);
  TrataArgumentosEntrada(argc, argv);
  InicializaEstruturas();
  GET_TIME(fim);
  lista_delta[0] = fim - inicio;
  printf("Pronto! (%lf)\n", lista_delta[0]);

  puts("Calculando produto das matrizes...");
  GET_TIME(inicio);
  CalculaProdutoMatrizes();
  GET_TIME(fim);
  lista_delta[1] = fim - inicio;
  printf("Pronto! (%lf)\n", lista_delta[1]);

  puts("Finalizando...");
  GET_TIME(inicio);
  EscreveMatriz(&matriz_saida);
  LiberaMemoria();
  GET_TIME(fim);
  lista_delta[2] = fim - inicio;
  printf("Pronto! (%lf)\n", lista_delta[2]);

  puts("-- RESUMO:");
  double total = lista_delta[0] + lista_delta[1] + lista_delta[2];
  printf("Inicialização: %.2lf%%\n", lista_delta[0]/total*100.0);
  printf("Processamento: %.2lf%%\n", lista_delta[1]/total*100.0);
  printf("Finalização: %.2lf%%\n", lista_delta[2]/total*100.0);

  return 0;
}

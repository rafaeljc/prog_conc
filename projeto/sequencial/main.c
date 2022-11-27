/*
  UFRJ
  Programação Concorrente 2022.2
  Profa. Silvana Rossetto

  Gauss-Jacobi (solução sequencial)
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "array.h"
#include "trata_argumentos_entrada.h"
#include "le_arquivos.h"
#include "gauss_jacobi.h"
#include "escreve_arquivo.h"
#include "timer.h"

extern bool sucesso;
extern array_t a;
extern array_t b;
extern array_t x0;
extern array_t x1;
extern int max_iter;
extern double e;

void libera_memoria() {
  free(a.elementos);
  free(b.elementos);
  free(x0.elementos);
  free(x1.elementos);
}

int main(int argc, char* argv[]) {
  trata_argumentos_entrada(argc, argv);
  
  double tempo_total = 0;
  double tempo_algoritmo = 0;
  double aux;

  printf("-- GAUSS-JACOBI (sequencial, e: %e, max_iter: %d)\n", e, max_iter);
  puts("Tentando resolver o sistema Ax = b...");

  GET_TIME(tempo_total);  
  le_arquivos();

  // algoritmo
  GET_TIME(aux);
  gauss_jacobi();
  GET_TIME(tempo_algoritmo);
  tempo_algoritmo -= aux;

  if (sucesso) escreve_arquivo("resultado_seq");
  libera_memoria();
  GET_TIME(aux);
  tempo_total = aux - tempo_total;

  if (sucesso) {
    puts("Sucesso!");
  } else {
    puts("Não foi possível resolver o sistema linear.");
  }

  printf("%.8lf\n", tempo_algoritmo);
  printf("%.8lf\n", tempo_total);

  return 0;
}

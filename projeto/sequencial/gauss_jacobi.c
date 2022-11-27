#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "array.h"
#include "gauss_jacobi.h"

bool sucesso = false;

// dados
array_t a;
array_t b;
array_t x0; // atual, x(k)
array_t x1; // próximo, x(k+1)
// parâmetros de parada do algoritmo
int max_iter = 2000;
double e = 1.0 / 100000000.0; // divisão para diminuir erro numérico

bool eh_vetor(array_t vetor) {
  if (vetor.num_linhas < 1) return false;
  if (vetor.num_colunas != 1) return false;
  return true;
}

bool sao_compativeis(array_t matriz, array_t vetor) {
  if (!eh_vetor(vetor)) return false;
  if (matriz.num_colunas != vetor.num_linhas) return false;
  return true;
}

void inicializa_vetor(array_t* vetor) {
  vetor->num_linhas = a.num_colunas;
  vetor->num_colunas = 1;
  // aloca memória pra armazenar os elementos
  double* elementos = (double*) malloc(sizeof(double) * vetor->num_linhas);
  if (!elementos) {
    fprintf(stderr, "ERRO: inicializa_vetor() -> malloc()\n");
    exit(GAUSS_JACOBI_ERRO_ALOC_MEM);
  }
  // inicializa todas as posições com valor 1
  for (int i = 0; i < vetor->num_linhas; i++) elementos[i] = 1;
  vetor->elementos = elementos;
  return;
}

double calcula_mod_dif(array_t vetor1, array_t vetor2) {
  double soma_quadrados = 0;
  for (int i = 0; i < vetor1.num_linhas; i++) {
    // soma += dif^2
    soma_quadrados += pow(vetor1.elementos[i] - vetor2.elementos[i], 2);
  }
  return sqrt(soma_quadrados);
}

void gauss_jacobi() {
  if (!sao_compativeis(a, b)) {
    fprintf(stderr, "A matriz e o vetor de entrada possuem dimensões incompatíveis!\n");
    exit(GAUSS_JACOBI_ERRO_DIM_INCOMP);
  }

  // inicializa vetores x
  inicializa_vetor(&x0);
  inicializa_vetor(&x1);

  // algoritmo gauss-jacobi
  for (int k = 0; k < max_iter; k++) {
    for (int i = 0; i < a.num_linhas; i++) {
      double somatorio = b.elementos[i];
      for (int j = 0; j < a.num_colunas; j++) {
        if (i != j) 
          somatorio -= a.elementos[i*a.num_colunas + j] * x0.elementos[j];
      }
      x1.elementos[i] = somatorio / a.elementos[i*a.num_colunas + i];
    }
    // verifica condição de parada
    if (calcula_mod_dif(x1, x0) < e) {
      printf("k = %d\n", k);
      sucesso = true;
      return;
    } else {
      // para economizar espaço e tempo de alocação dinâmica de memória
      // inverte as referencias dos elementos de x0 com x1
      double* aux;
      aux = x0.elementos;
      x0.elementos = x1.elementos;
      x1.elementos = aux;
    }
  }

  return;
}

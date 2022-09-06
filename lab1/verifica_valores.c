#include <stdio.h>
#include <math.h>

#include "estruturas.h"

void VerificaValores(Vetor *vetor) {
  float n, erro;
  for (int i = 0; i < vetor->tamanho; i++) {
    //printf("%d -> %f\n", (i + 1), vetor->elementos[i]);
    n = (i + 1)*1.10;
    // calculando o erro relativo
    erro = fabs(n - vetor->elementos[i])/n;
    if (erro > 0.00000001) {
      printf("Falhou!\n");
      return;
    }    
  }
  printf("Sucesso!\n");
}

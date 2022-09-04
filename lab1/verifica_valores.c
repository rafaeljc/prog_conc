#include <stdio.h>

#include "estruturas.h"

void VerificaValores(Vetor *vetor) {
  float n;
  for (int i = 0; i < vetor->tamanho; i++) {
    printf("%d -> %f\n", (i + 1), vetor->elementos[i]);
    n = (i + 1)*1.10;
    if (vetor->elementos[i] != n) {
      printf("Falhou!\n");
      return;
    }    
  }
  printf("Sucesso!\n");
}

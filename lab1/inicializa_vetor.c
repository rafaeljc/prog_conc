#include "estruturas.h"

void InicializaVetor(Vetor *vetor) {
  for (int i = 0; i < vetor->tamanho; i++)
    vetor->elementos[i] = (float) i + 1;
}

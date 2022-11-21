#include <stdlib.h>

#include "array.h"

int array_init(array_t* array, int num_linhas, int num_colunas) {
  if (!array) return ARRAY_ERRO_END_NULL;
  if (num_linhas < 1 || num_colunas < 1) return ARRAY_ERRO_ARG_INVALIDO;
  array->num_linhas = num_linhas;
  array->num_colunas = num_colunas;
  array->elementos = (double*) malloc(sizeof(double) * num_linhas * num_colunas);
  if (!array->elementos) return ARRAY_ERRO_ALOC_MEM;

  return 0;
}

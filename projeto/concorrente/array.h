#ifndef ARRAY_H
#define ARRAY_H

#define ARRAY_ERRO_END_NULL 20
#define ARRAY_ERRO_ARG_INVALIDO 21
#define ARRAY_ERRO_ALOC_MEM 22

typedef struct {
  int num_linhas;
  int num_colunas;
  double* elementos;
} array_t;

int array_init(array_t* array, int num_linhas, int num_colunas);

#endif // ARRAY_H

#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

typedef struct {
  char* nome_arquivo;
  float* elementos;
  int num_linhas;
  int num_colunas;
} Matriz;
void InstanciaMatriz(Matriz* matriz, int num_linhas, int num_colunas);
void LeMatriz(Matriz* matriz);
void EscreveMatriz(Matriz* matriz);

#endif // ESTRUTURAS_H

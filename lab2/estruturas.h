#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

typedef struct {
  float* elementos;
  int num_linhas;
  int num_colunas;
} Matriz;
void InstanciaMatriz(Matriz* matriz, int num_linhas, int num_colunas);
void LeMatriz(Matriz* matriz, char* nome_arquivo);
void EscreveMatriz(Matriz* matriz, char* nome_arquivo);

#endif // ESTRUTURAS_H

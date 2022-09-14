#include <stdio.h>
#include <stdlib.h>

#include "estruturas.h"

extern Matriz matriz_1;
extern Matriz matriz_2;
extern Matriz matriz_saida;

void TrataArgumentosEntrada(int argc, char* argv[]) {
  if (argc != 4) {
    fprintf(stderr, "Argumento inválido ou inexistente!\n");
    fprintf(stderr, "Uso: %s <matriz 1> <matriz 2> <matriz saída>\n", argv[0]);
    exit(1);
  }
  matriz_1.nome_arquivo = argv[1];
  matriz_2.nome_arquivo = argv[2];
  matriz_saida.nome_arquivo = argv[3];
}

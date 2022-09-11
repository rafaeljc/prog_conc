#include <stdio.h>
#include <stdlib.h>

#include "estruturas.h"

extern char* nome_arq_matriz_1;
extern char* nome_arq_matriz_2;
extern char* nome_arq_matriz_saida;

void TrataArgumentosEntrada(int argc, char* argv[]) {
  if (argc != 4) {
    fprintf(stderr, "Argumento inválido ou inexistente!\n");
    fprintf(stderr, "Uso: %s <matriz 1> <matriz 2> <matriz saída>\n", argv[0]);
    exit(1);
  }
  nome_arq_matriz_1 = argv[1];
  nome_arq_matriz_2 = argv[2];
  nome_arq_matriz_saida = argv[3];
}

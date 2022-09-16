#include <stdio.h>
#include <stdlib.h>

#include "matriz.h"

extern Matriz matriz_1;
extern Matriz matriz_2;
extern Matriz matriz_saida;
extern int num_threads;

void TrataArgumentosEntrada(int argc, char* argv[]) {
  switch (argc) {
    case 5:
      num_threads = atoi(argv[4]);
    case 4:
      matriz_1.nome_arquivo = argv[1];
      matriz_2.nome_arquivo = argv[2];
      matriz_saida.nome_arquivo = argv[3];
      break;  
    default:
      fprintf(stderr, "Argumento inválido ou inexistente!\n");
      fprintf(stderr, "Uso: %s <matriz 1> <matriz 2> <matriz saída> [número de threads]\n", argv[0]);
      exit(1);
  }  
}

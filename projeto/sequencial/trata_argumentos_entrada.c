#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "erros.h"

extern int max_iter;
extern double e;

char* nome_arq_matriz_a = NULL;
char* nome_arq_vetor_b = NULL;

void imprime_msg_argumento_invalido(char* arquivo) {
  fprintf(stderr, "Argumento inválido!\n");
  fprintf(stderr, "Uso: %s <matriz A> <vetor b> [-max_iter <num>] [-e <num>]\n", arquivo);
  exit(ERRO_ARG_INVALIDO);
}

// valida, de forma simples, se o arquivo não possui extensão
bool eh_arq_sem_extensao(char* nome_arquivo) {
  char* possui_ponto = strchr(nome_arquivo, '.'); // primeira ocorrência de '.'
  if (!possui_ponto) return true;
  return false;
}

void trata_argumentos_entrada(int argc, char* argv[]) {
  if (argc < 3) imprime_msg_argumento_invalido(argv[0]);
  // matriz A
  if (!eh_arq_sem_extensao(argv[1])) imprime_msg_argumento_invalido(argv[0]);
  nome_arq_matriz_a = argv[1];
  // vetor b
  if (!eh_arq_sem_extensao(argv[2])) imprime_msg_argumento_invalido(argv[0]);
  nome_arq_vetor_b = argv[2];

  // argumentos opcionais
  if (argc > 3) {    
    for (int i = 3; i < argc; i += 2) {
      // verifica se existe o valor do parâmetro
      if (i + 1 >= argc) imprime_msg_argumento_invalido(argv[0]);
      
      if (strcmp(argv[i], "-max_iter") == 0) {
        max_iter = atoi(argv[i + 1]);
        continue;
      }
      if (strcmp(argv[i], "-e") == 0) {
        e = atof(argv[i + 1]);
        continue;
      }
      
      // caso não seja nenhum dos parâmetros acima
      imprime_msg_argumento_invalido(argv[0]);
    }
  }

  return;
}

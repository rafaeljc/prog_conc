#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "erros.h"

char* arquivo_entrada = NULL;

void imprime_msg_argumento_invalido(char* arquivo) {
  fprintf(stderr, "Argumento inválido!\n");
  fprintf(stderr, "Uso: %s <arquivo_binario>\n", arquivo);
  exit(ERRO_ARG_INVALIDO);
}

// valida, de forma simples, se o arquivo não possui extensão
bool eh_arq_sem_extensao(char* nome_arquivo) {
  char* possui_ponto = strchr(nome_arquivo, '.'); // primeira ocorrência de '.'
  if (!possui_ponto) return true;
  return false;
}

void trata_argumentos_entrada(int argc, char* argv[]) {  
  // valida se possui apenas 1 argumento de entrada
  if (argc != 2) imprime_msg_argumento_invalido(argv[0]);

  if (!eh_arq_sem_extensao(argv[1])) imprime_msg_argumento_invalido(argv[0]);
  
  arquivo_entrada = argv[1];

  return;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "erros.h"

char* arquivo_entrada = NULL;
char* arquivo_saida = NULL;

void imprime_msg_argumento_invalido(char* arquivo) {
  fprintf(stderr, "Argumento inválido!\n");
  fprintf(stderr, "Uso: %s <arquivo.txt>\n", arquivo);
  exit(ERRO_ARG_INVALIDO);
}

// valida se o arquivo possui extensão .txt
bool eh_arquivo_txt(char* nome_arquivo) {
  char* extensao = strrchr(nome_arquivo, '.'); // última ocorrência de '.'
  if (!extensao) return false;
  bool nao_txt = strcmp(extensao, ".txt");
  if (nao_txt) return false;
  return true;
}

char* nome_sem_extensao(char* nome_arquivo) {
  int tam_nome = strlen(nome_arquivo) - 4; // ".txt"
  char* nome = (char*) malloc(tam_nome + 1); // '\0'
  if (!nome) {
    fprintf(stderr, "Erro: nome_sem_extensao() -> malloc()\n");
    exit(ERRO_ALOC_MEMORIA);
  }
  strncpy(nome, nome_arquivo, tam_nome);
  nome[tam_nome] = '\0';
  return nome;
}

void trata_argumentos_entrada(int argc, char* argv[]) {  
  // valida se possui apenas 1 argumento de entrada
  if (argc != 2) imprime_msg_argumento_invalido(argv[0]);

  if (!eh_arquivo_txt(argv[1])) imprime_msg_argumento_invalido(argv[0]);
  
  arquivo_entrada = argv[1];
  arquivo_saida = nome_sem_extensao(arquivo_entrada);

  return;
}

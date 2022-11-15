#include <stdio.h>
#include <stdlib.h>

#include "erros.h"

extern unsigned int num_linhas;
extern unsigned int num_colunas;
extern double* array;

void imprime_msg_erro_escreve_arquivo(char* nome_arquivo) {
  fprintf(stderr, "Erro ao escrever no arquivo %s\n", nome_arquivo);
  exit(ERRO_ESCREVER_ARQUIVO);
}

void escreve_arquivo(char* nome_arquivo) {
  if (!nome_arquivo) {
    fprintf(stderr, "Nome de arquivo NULL!\n");
    exit(ERRO_NOME_ARQ_NULL);
  }

  FILE* arquivo;
  arquivo = fopen(nome_arquivo, "wb");
  if (!arquivo) {
    fprintf(stderr, "Não foi possível criar o arquivo %s\n", nome_arquivo);
    exit(ERRO_CRIAR_ARQUIVO);
  }

  // escreve número de linhas e colunas
  if (!fwrite(&num_linhas, sizeof(unsigned int), 1, arquivo))
    imprime_msg_erro_escreve_arquivo(nome_arquivo);
  if (!fwrite(&num_colunas, sizeof(unsigned int), 1, arquivo))
    imprime_msg_erro_escreve_arquivo(nome_arquivo);

  // escreve elementos do array
  if (!fwrite(array, sizeof(double), num_linhas * num_colunas, arquivo))
    imprime_msg_erro_escreve_arquivo(nome_arquivo);

  free(array);
  fclose(arquivo);

  return;
}

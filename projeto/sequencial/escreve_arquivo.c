#include <stdio.h>
#include <stdlib.h>

#include "array.h"
#include "erros.h"

extern array_t x1;

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
  if (!fwrite(&x1.num_linhas, sizeof(int), 1, arquivo))
    imprime_msg_erro_escreve_arquivo(nome_arquivo);
  if (!fwrite(&x1.num_colunas, sizeof(int), 1, arquivo))
    imprime_msg_erro_escreve_arquivo(nome_arquivo);

  // escreve elementos do array
  if (!fwrite(x1.elementos, sizeof(double), x1.num_linhas * x1.num_colunas, arquivo))
    imprime_msg_erro_escreve_arquivo(nome_arquivo);

  fclose(arquivo);

  return;
}

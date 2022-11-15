#include <stdio.h>
#include <stdlib.h>

#include "erros.h"

void imprime_msg_erro_le_arquivo(char* nome_arquivo) {
  fprintf(stderr, "Erro ao ler o arquivo %s\n", nome_arquivo);
  exit(ERRO_LER_ARQUIVO);
}

void le_arquivo(char* nome_arquivo) {
  if (!nome_arquivo) {
    fprintf(stderr, "Nome de arquivo NULL!\n");
    exit(ERRO_NOME_ARQ_NULL);
  }

  FILE* arquivo;
  arquivo = fopen(nome_arquivo, "rb");
  if (!arquivo) {
    fprintf(stderr, "Não foi possível abrir o arquivo %s\n", nome_arquivo);
    exit(ERRO_ABRIR_ARQUIVO);
  }

  // lê número de linhas e colunas
  unsigned int num_linhas = 0;
  unsigned int num_colunas = 0;
  if (!fread(&num_linhas, sizeof(unsigned int), 1, arquivo))
    imprime_msg_erro_le_arquivo(nome_arquivo);
  if (!fread(&num_colunas, sizeof(unsigned int), 1, arquivo))
    imprime_msg_erro_le_arquivo(nome_arquivo);

  // aloca memoria pra armazenar o array
  double* array = (double*) malloc(sizeof(double)*num_linhas*num_colunas);
  if (!array) {
    fprintf(stderr, "Erro: le_arquivo() -> malloc()\n");
    exit(ERRO_ALOC_MEMORIA);
  }

  // lê elementos do array
  if (!fread(array, sizeof(double), num_linhas*num_colunas, arquivo))
    imprime_msg_erro_le_arquivo(nome_arquivo);

  // exibe a saida
  printf("(%u x %u)\n", num_linhas, num_colunas);
  for (unsigned int i = 0; i < num_linhas; i++) {
    printf("[ ");
    for (unsigned int j = 0; j < num_colunas; j++) {
      printf("%lf ", array[i*num_colunas + j]);
    }
    printf("]\n");
  }

  fclose(arquivo);

  return;
}

#include <stdio.h>
#include <stdlib.h>

#include "erros.h"

int num_linhas = 0;
int num_colunas = 0;
double* array = NULL;

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
  arquivo = fopen(nome_arquivo, "r");
  if (!arquivo) {
    fprintf(stderr, "Não foi possível abrir o arquivo %s\n", nome_arquivo);
    exit(ERRO_ABRIR_ARQUIVO);
  }

  // lê número de linhas e colunas
  if (!fscanf(arquivo, "%d", &num_linhas))
    imprime_msg_erro_le_arquivo(nome_arquivo);
  if (!fscanf(arquivo, "%d", &num_colunas))
    imprime_msg_erro_le_arquivo(nome_arquivo);

  // aloca memoria pra armazenar o array
  array = (double*) malloc(sizeof(double)*num_linhas*num_colunas);
  if (!array) {
    fprintf(stderr, "ERRO: le_arquivo() -> malloc()\n");
    exit(ERRO_ALOC_MEMORIA);
  }

  // lê elementos do array
  for (int i = 0; i < num_linhas; i++) {
    for (int j = 0; j < num_colunas; j++) {
      if (!fscanf(arquivo, "%lf", &array[i*num_colunas + j]))
        imprime_msg_erro_le_arquivo(nome_arquivo);
    }
  }

  fclose(arquivo);

  return;
}

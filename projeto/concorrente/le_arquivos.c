#include <stdio.h>
#include <stdlib.h>

#include "array.h"
#include "erros.h"

extern char* nome_arq_matriz_a;
extern char* nome_arq_vetor_b;
extern array_t a;
extern array_t b;

void imprime_msg_erro_le_arquivo(char* nome_arquivo) {
  fprintf(stderr, "Erro ao ler o arquivo %s\n", nome_arquivo);
  exit(ERRO_LER_ARQUIVO);
}

void recupera_dados(char* nome_arquivo, array_t* array) {
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
  int num_linhas = 0;
  int num_colunas = 0;
  if (!fread(&num_linhas, sizeof(int), 1, arquivo))
    imprime_msg_erro_le_arquivo(nome_arquivo);
  array->num_linhas = num_linhas;
  if (!fread(&num_colunas, sizeof(int), 1, arquivo))
    imprime_msg_erro_le_arquivo(nome_arquivo);
  array->num_colunas = num_colunas;

  // aloca memoria pra armazenar os elementos do array
  double* elementos = (double*) malloc(sizeof(double)*num_linhas*num_colunas);
  if (!elementos) {
    fprintf(stderr, "ERRO: recupera_dados() -> malloc()\n");
    exit(ERRO_ALOC_MEMORIA);
  }  
  // lê elementos do array
  if (!fread(elementos, sizeof(double), num_linhas*num_colunas, arquivo))
    imprime_msg_erro_le_arquivo(nome_arquivo);
  array->elementos = elementos;

  fclose(arquivo);

  return;
}

void le_arquivos() {
  recupera_dados(nome_arq_matriz_a, &a);
  recupera_dados(nome_arq_vetor_b, &b);
  return;
}

#include <stdio.h>
#include <stdlib.h>

#include "estruturas.h"

void InstanciaMatriz(Matriz* matriz, int num_linhas, int num_colunas) {
  matriz->num_linhas = num_linhas;
  matriz->num_colunas = num_colunas;
  matriz->elementos = (float*) malloc(num_linhas*num_colunas*sizeof(float));
  if (matriz->elementos == NULL) {
    fprintf(stderr, "Não foi possível alocar memória pra matriz!\n");
    exit(-1);
  }
}

void LeMatriz(Matriz* matriz, char* nome_arquivo) {
  FILE* arquivo;
  size_t ret; // retorno da função de leitura
  int num_linhas;
  int num_colunas;

  arquivo = fopen(nome_arquivo, "rb");
  if (!arquivo) {
    fprintf(stderr, "Não foi possível abrir o arquivo: %s\n", nome_arquivo);
    exit(2);
  }
  
  // dimensões da matriz
  ret = fread(&num_linhas, sizeof(int), 1, arquivo);
  if (!ret) {
    fprintf(stderr, "Não foi possível ler o número de linhas da matriz!\n");
    exit(3);
  }
  ret = fread(&num_colunas, sizeof(int), 1, arquivo);
  if (!ret) {
    fprintf(stderr, "Não foi possível ler o número de colunas da matriz!\n");
    exit(3);
  }

  InstanciaMatriz(matriz, num_linhas, num_colunas);

  // elementos da matriz
  ret = fread(matriz->elementos, sizeof(float), num_linhas*num_colunas, arquivo);
  if (!ret) {
    fprintf(stderr, "Não foi possível ler os elementos da matriz!\n");
    exit(3);
  }

  fclose(arquivo);
}

void EscreveMatriz(Matriz* matriz, char* nome_arquivo) {
  FILE* arquivo;
  size_t ret; // retorno da função de escrita

  arquivo = fopen(nome_arquivo, "wb");
  if (!arquivo) {
    fprintf(stderr, "Não foi possível criar o arquivo: %s\n", nome_arquivo);
    exit(2);
  }

  // dimensões da matriz
  ret = fwrite(&matriz->num_linhas, sizeof(int), 1, arquivo);
  ret = fwrite(&matriz->num_colunas, sizeof(int), 1, arquivo);
  // elementos da matriz
  int tamanho = matriz->num_linhas*matriz->num_colunas;
  ret = fwrite(matriz->elementos, sizeof(float), tamanho, arquivo);
  if (ret < tamanho) {
    fprintf(stderr, "Não foi possível escrever a matriz no arquivo!\n");
    exit(3);
  }

  fclose(arquivo);
}

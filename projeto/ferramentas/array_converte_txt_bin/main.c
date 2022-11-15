/*
  Armazena um array contido em um arquivo.txt em um arquivo binário.

  Estrutura do arquivo.txt:
    + primeira linha contém as dimensões do array
      <num_linhas> <num_colunas> (valores inteiros separados por espaço)
    + cada uma das demais linhas do arquivo representa uma linha do array
      <ele1> <ele2> .. <eleN> (valores decimais separados por espaço)
    exemplo:
      3 2
      1.1 1.2
      2.1 2.2
      3.1 3.3

  Estrutura do arquivo binário:
    [0]   (int) número de linhas
    [1]   (int) número de colunas
    [2:]  (double) sequência de elementos
*/
#include "trata_argumentos_entrada.h"
#include "le_arquivo.h"
#include "escreve_arquivo.h"

extern char* arquivo_entrada;
extern char* arquivo_saida;

int main(int argc, char* argv[]) {
  trata_argumentos_entrada(argc, argv);
  le_arquivo(arquivo_entrada);
  escreve_arquivo(arquivo_saida);

  return 0;
}

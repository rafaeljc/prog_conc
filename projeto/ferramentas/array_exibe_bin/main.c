/*
  Exibe um array armazenado em um arquivo binário

  Formato da saída:
  (<num_linhas> x <num_colunas)
  [ ele ele .. ele ]
  [ ele ele .. ele ]
  [ ... ...    ... ]
  [ ele ele .. ele ]
*/
#include "trata_argumentos_entrada.h"
#include "le_arquivo.h"

extern char* arquivo_entrada;

int main(int argc, char* argv[]) {
  trata_argumentos_entrada(argc, argv);
  le_arquivo(arquivo_entrada);

  return 0;
}

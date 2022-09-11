/* Programação Concorrente 2022.2
   Laboratório 2
*/
#include "calcula_produto_matrizes.h"
#include "estruturas.h"
#include "inicializa_estruturas.h"
#include "libera_memoria.h"
#include "timer.h"
#include "trata_argumentos_entrada.h"

char* nome_arq_matriz_1;
char* nome_arq_matriz_2;
char* nome_arq_matriz_saida;
Matriz matriz_1;
Matriz matriz_2;
Matriz matriz_saida;

int main(int argc, char* argv[]) {
  TrataArgumentosEntrada(argc, argv);
  InicializaEstruturas();
  CalculaProdutoMatrizes();
  EscreveMatriz(&matriz_saida, nome_arq_matriz_saida);
  LiberaMemoria();

  return 0;
}

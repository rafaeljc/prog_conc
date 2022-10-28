/* Programação Concorrente 2022.2
   Laboratório 7
*/
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#include "controle_threads.h"
#include "trata_argumentos_entrada.h"

int main(int argc, char* argv[]) {
  pthread_t* threads;
  int* threads_ids;
  // valores em num_threads
  // [0]: total de threads
  // [1]: número de produtores
  // [2]: número de consumidores
  int num_threads[] = {2, 1, 1}; // default

  srand(time(NULL)); // seta seed para gerar strings aleatórias
  TrataArgumentosEntrada(argc, argv, num_threads, &threads, &threads_ids);
  InicializaVariaveisControle();
  InicializaBuffer();
  InicializaThreads(num_threads, threads, threads_ids);
  AguardaExecucaoThreads(threads, num_threads[0]);
  DestroiVariaveisControle();
  LiberaMemoria(threads, threads_ids);

  return 0;
}

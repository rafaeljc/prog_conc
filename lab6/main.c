/* Programação Concorrente 2022.2
   Laboratório 6
*/
#include <pthread.h>

#include "controle_threads.h"
#include "trata_argumentos_entrada.h"

int main(int argc, char* argv[]) {
  pthread_t* threads;
  int* threads_ids;
  // valores em num_threads
  // [0]: total de tarefas
  // [1]: número de Tarefa1
  // [2]: número de Tarefa2
  // [3]: número de Tarefa3
  int num_threads[] = {3, 1, 1, 1}; // default

  TrataArgumentosEntrada(argc, argv, num_threads, &threads, &threads_ids);
  InicializaVariaveisControle();
  InicializaThreads(num_threads, threads, threads_ids);
  AguardaExecucaoThreads(threads, num_threads[0]);  
  LiberaVariaveisControle();
  LiberaMemoria(threads, threads_ids);
  
  return 0;
}

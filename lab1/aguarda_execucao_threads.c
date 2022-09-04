#include "estruturas.h"

void AguardaExecucaoThreads(ListaDeThreads *lista_threads) {
  for (int t_id = 0; t_id < lista_threads->tamanho; t_id++)
    pthread_join(lista_threads->threads[t_id], NULL);
}

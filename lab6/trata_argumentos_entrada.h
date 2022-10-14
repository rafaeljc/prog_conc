#ifndef TRATA_ARGUMENTOS_ENTRADA_H
#define TRATA_ARGUMENTOS_ENTRADA_H

#include <pthread.h>

void TrataArgumentosEntrada(int argc, char* argv[], int num_threads[], pthread_t** threads, int** threads_ids);
void LiberaMemoria(pthread_t* threads, int* threads_ids);

#endif // TRATA_ARGUMENTOS_ENTRADA_H

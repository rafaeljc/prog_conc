#include <pthread.h>

#include "imprime_frase.h"

extern const unsigned long tam_lista;

extern pthread_mutex_t mutex;
extern pthread_cond_t cond_pode_imprimir;

void InicializaVariaveisDeControle(void) {
  pthread_mutex_init(&mutex, NULL);
  pthread_cond_init(&cond_pode_imprimir, NULL);
}

void LiberaVariaveisDeControle(void) {
  pthread_mutex_destroy(&mutex);
  pthread_cond_destroy(&cond_pode_imprimir);
}

void CriaThreads(pthread_t threads[], int threads_ids[]) {
  for (int i = 0; i < tam_lista; i++) {
    threads_ids[i] = i;
    pthread_create(&threads[i], NULL, imprime_frase, (void*) &threads_ids[i]);
  }
}

void AguardaExecucaoThreads(pthread_t threads[]) {
  for (int i = 0; i < tam_lista; i++) {
    pthread_join(threads[i], NULL);
  }
}

#ifndef CONTROLE_THREADS_H
#define CONTROLE_THREADS_H

#include <pthread.h>

void InicializaVariaveisDeControle(void);
void LiberaVariaveisDeControle(void);

void CriaThreads(pthread_t threads[], int threads_ids[]);
void AguardaExecucaoThreads(pthread_t threads[]);

#endif // CONTROLE_THREADS_H

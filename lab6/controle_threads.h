#ifndef CONTROLE_THREADS_H
#define CONTROLE_THREADS_H

void InicioLeitura(int id);
void FimLeitura(int id);

void InicioEscrita(int id);
void FimEscrita(int id);

void InicializaVariaveisControle(void);
void LiberaVariaveisControle(void);

void InicializaThreads(int num_threads[], pthread_t threads[], int threads_ids[]);
void AguardaExecucaoThreads(pthread_t threads[], int total_threads);

#endif // CONTROLE_THREADS_H

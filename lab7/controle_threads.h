#ifndef CONTROLE_THREADS_H
#define CONTROLE_THREADS_H

void Insere(char* str, int id);
char Retira(int id);

void InicializaBuffer(void);
void InicializaVariaveisControle(void);
void DestroiVariaveisControle(void);

void InicializaThreads(int num_threads[], pthread_t threads[], int threads_ids[]);
void AguardaExecucaoThreads(pthread_t threads[], int total_threads);

#endif // CONTROLE_THREADS_H

#ifndef TAREFAS_H
#define TAREFAS_H

#include <pthread.h>

void* Tarefa1(void* arg);
void* Tarefa2(void* arg);
void* Tarefa3(void* arg);

void IniciaThreads(pthread_t threads[], int threads_ids[]);

#endif // TAREFAS_H

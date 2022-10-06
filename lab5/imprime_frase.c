#include <stdio.h>
#include <pthread.h>

#include "imprime_frase.h"

extern const char* lista_frases[];
extern const unsigned long tam_lista;
extern const int id_primeira;
extern const int id_ultima;

extern pthread_mutex_t mutex;
extern pthread_cond_t cond_pode_imprimir;
extern int num_impressoes;

void* imprime_frase(void* arg) {
  int id = *((int*) arg);

  pthread_mutex_lock(&mutex);

  // primeira frase a ser impressa
  if (id == id_primeira) {
    puts(lista_frases[id]);
    num_impressoes++;
    pthread_cond_broadcast(&cond_pode_imprimir);
  }
  // última frase a ser impressa  
  else if (id == id_ultima) {
    // aguarda as outras frases serem impressas
    while (num_impressoes < (tam_lista - 1))
      pthread_cond_wait(&cond_pode_imprimir, &mutex);      
    puts(lista_frases[id]);
  }
  // demais frases a serem impressas
  else {
    // aguarda a primeira frase ser impressa
    while (num_impressoes < 1)
      pthread_cond_wait(&cond_pode_imprimir, &mutex);
    puts(lista_frases[id]);
    num_impressoes++;
    pthread_cond_broadcast(&cond_pode_imprimir);
  }
  
  pthread_mutex_unlock(&mutex);
  pthread_exit(NULL);
}

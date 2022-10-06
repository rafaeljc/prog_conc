/* Programação Concorrente 2022.2
   Laboratório 5
*/
#include <pthread.h>

#include "controle_threads.h"

// lista de frases a serem impressas
// a primeira frase da lista será a ÚLTIMA a ser impressa
// a última frase da lista será a PRIMEIRA a ser impressa
// as demais frases serão impressas em qualquer ordem (exceto PRIMEIRA e ÚLTIMA)
const char* lista_frases[] = {
  "Volte sempre!",
  "Fique a vontade.",
  "Sente-se por favor.",  
  "Seja bem-vindo!",
};
const unsigned long tam_lista = sizeof(lista_frases) / sizeof(char*);
const int id_primeira = tam_lista - 1;
const int id_ultima = 0;

// variáveis para controle das threads
pthread_mutex_t mutex;
pthread_cond_t cond_pode_imprimir;
int num_impressoes = 0;

int main(int argc, char* argv[]) {
  pthread_t threads[tam_lista];
  int threads_ids[tam_lista];

  InicializaVariaveisDeControle();
  CriaThreads(threads, threads_ids);
  AguardaExecucaoThreads(threads);
  LiberaVariaveisDeControle();

  return 0;
}

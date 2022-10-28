#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#include "controle_threads.h"

extern char* buffer;
extern const int tam_buffer;

char* GeraString(int tamanho) {
  // aloca uma posição a mais por causa do caractere '\0'
  char* str = (char*) malloc(sizeof(char) * (tamanho + 1));
  if (!str) {
    fprintf(stderr, "ERRO: GeraString() -> malloc()\n");
    exit(-1);
  }

  char comeco = 'A';
  char final = 'Z';
  for (int i = 0; i < tamanho; i++) {
    str[i] = (rand() %  (final - comeco + 1)) + comeco;
  }
  // indica o final da string
  str[tamanho] = '\0';

  return str;
}

// gera string aleatória e coloca no buffer
void* produtor(void* arg) {
  int id = *((int*) arg);
  char* str;
  while (true) {
    str = GeraString(tam_buffer);
    printf("P(%d): Produziu %s\n", id, str);
    Insere(str, id);
    free(str);
  }
  pthread_exit(NULL);
}

// retira um caractere da string
void* consumidor(void* arg) {
  int id = *((int*) arg);
  char c;
  while (true) {    
    c = Retira(id);
    // retirou mas não faz nada
  }
  pthread_exit(NULL);
}

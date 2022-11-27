#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <pthread.h>

#include "array.h"
#include "gauss_jacobi.h"

bool sucesso = false;
bool continua = true;

// dados
array_t a;
array_t b;
array_t x0; // atual, x(k)
array_t x1; // próximo, x(k+1)
// parâmetros de parada do algoritmo
int max_iter = 2000;
double e = 1.0 / 100000000.0; // divisão para diminuir erro numérico
// variáveis para controle e sincronização das threads
int num_threads = 2; // default
int contador = 0;
pthread_mutex_t mutex;
pthread_cond_t fila_barreira;

bool eh_vetor(array_t vetor) {
  if (vetor.num_linhas < 1) return false;
  if (vetor.num_colunas != 1) return false;
  return true;
}

bool sao_compativeis(array_t matriz, array_t vetor) {
  if (!eh_vetor(vetor)) return false;
  if (matriz.num_colunas != vetor.num_linhas) return false;
  return true;
}

void inicializa_vetor(array_t* vetor) {
  vetor->num_linhas = a.num_colunas;
  vetor->num_colunas = 1;
  // aloca memória pra armazenar os elementos
  double* elementos = (double*) malloc(sizeof(double) * vetor->num_linhas);
  if (!elementos) {
    fprintf(stderr, "ERRO: inicializa_vetor() -> malloc()\n");
    exit(GAUSS_JACOBI_ERRO_ALOC_MEM);
  }
  // inicializa todas as posições com valor 1
  for (int i = 0; i < vetor->num_linhas; i++) elementos[i] = 1;
  vetor->elementos = elementos;
  return;
}

double calcula_mod_dif(array_t vetor1, array_t vetor2) {
  double soma_quadrados = 0;
  for (int i = 0; i < vetor1.num_linhas; i++) {
    // soma += dif^2
    soma_quadrados += pow(vetor1.elementos[i] - vetor2.elementos[i], 2);
  }
  return sqrt(soma_quadrados);
}

bool condicao_parada() {
  static int k = 0; // contador de iterações do algoritmo
  // convergiu para o resultado
  if (calcula_mod_dif(x1, x0) < e) {
    printf("k = %d\n", k);
    sucesso = true; 
    return true;
  }
  // limite de iterações
  k++;
  if (k >= max_iter) {
    return true;
  }
  // para economizar espaço e tempo de alocação dinâmica de memória
  // inverte as referencias dos elementos de x0 com x1
  double* aux;
  aux = x0.elementos;
  x0.elementos = x1.elementos;
  x1.elementos = aux;  
  return false;
}

void barreira() {
  pthread_mutex_lock(&mutex);
  contador++;
  if (contador < num_threads) { // se não sou o último
    pthread_cond_wait(&fila_barreira, &mutex);
  } else {
    if (condicao_parada()) continua = false;
    contador = 0;
    pthread_cond_broadcast(&fila_barreira);
  }
  pthread_mutex_unlock(&mutex);
  return;
}

// para um melhor balanceamento de carga das threads
// dividir em fatias contínuas de dados
void define_limites_iteracao(int id, int* inicio, int* fim) {
  int tam_fatia = (a.num_linhas / num_threads) + 1;
  *inicio = tam_fatia * id;
  *fim = *inicio + tam_fatia;
  if (*fim > a.num_linhas) *fim = a.num_linhas;
  return;
}

void* executa_algoritmo(void* args) {
  int id = *((int*) args);
  int inicio_iter;
  int fim_iter;
  define_limites_iteracao(id, &inicio_iter, &fim_iter);
  while (continua) {
    for (int i = inicio_iter; i < fim_iter; i++) {
      double somatorio = b.elementos[i];
      for (int j = 0; j < a.num_colunas; j++) {
        if (i != j) 
          somatorio -= a.elementos[i*a.num_colunas + j] * x0.elementos[j];
      }
      x1.elementos[i] = somatorio / a.elementos[i*a.num_colunas + i];
    }
    barreira();
  }
  pthread_exit(NULL);
}

void cria_threads(pthread_t threads[], int threads_ids[]) {
  for (int i = 0; i < num_threads; i++) {
    threads_ids[i] = i;
    if (pthread_create(&threads[i], NULL, executa_algoritmo, (void*) &threads_ids[i])) {
      fprintf(stderr, "Não foi possível iniciar a thread %d!\n", threads_ids[i]);
      exit(GAUSS_JACOBI_ERRO_INI_THREAD);
    }
  }
  return;
}

void aguarda_execucao_threads(pthread_t threads[], int threads_ids[]) {
  for (int i = 0; i < num_threads; i++) {
    if (pthread_join(threads[i], NULL)) {
      fprintf(stderr, "Erro ao aguardar execução da thread %d!\n", threads_ids[i]);
      exit(GAUSS_JACOBI_ERRO_AGU_EXE_THREAD);
    }
  }
}

void gauss_jacobi() {
  if (!sao_compativeis(a, b)) {
    fprintf(stderr, "A matriz e o vetor de entrada possuem dimensões incompatíveis!\n");
    exit(GAUSS_JACOBI_ERRO_DIM_INCOMP);
  }

  // inicializa vetores x
  inicializa_vetor(&x0);
  inicializa_vetor(&x1);

  pthread_mutex_init(&mutex, NULL);
  pthread_cond_init(&fila_barreira, NULL);

  pthread_t* threads = (pthread_t*) malloc(sizeof(pthread_t) * num_threads);
  if (!threads) {
    fprintf(stderr, "Não foi possível alocar memória para as threads\n");
    exit(GAUSS_JACOBI_ERRO_ALOC_MEM);
  }
  int* threads_ids = (int*) malloc(sizeof(int) * num_threads);;
  if (!threads_ids) {
    fprintf(stderr, "Não foi possível alocar memória para os ids das threads\n");
    exit(GAUSS_JACOBI_ERRO_ALOC_MEM);
  }

  cria_threads(threads, threads_ids);
  aguarda_execucao_threads(threads, threads_ids);

  return;
}

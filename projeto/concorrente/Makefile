CC = gcc

PRE_OBJS = main.c array.c trata_argumentos_entrada.c le_arquivos.c gauss_jacobi.c escreve_arquivo.c
PRE_COMPILER_FLAGS = -c -O

OBJS = main.o array.o trata_argumentos_entrada.o le_arquivos.o gauss_jacobi.o escreve_arquivo.o
COMPILER_FLAGS = -Wall -lm -lpthread
OUT_NAME = gauss-jacobi

all: $(PRE_OBJS) $(OBJS)
	$(CC) $(PRE_OBJS) $(PRE_COMPILER_FLAGS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) -o $(OUT_NAME)

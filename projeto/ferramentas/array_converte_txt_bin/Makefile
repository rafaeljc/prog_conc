CC = gcc

PRE_OBJS = main.c trata_argumentos_entrada.c le_arquivo.c escreve_arquivo.c
PRE_COMPILER_FLAGS = -c -O

OBJS = main.o trata_argumentos_entrada.o le_arquivo.o escreve_arquivo.o
COMPILER_FLAGS = -Wall
OUT_NAME = array_converte_txt_bin

all: $(PRE_OBJS) $(OBJS)
	$(CC) $(PRE_OBJS) $(PRE_COMPILER_FLAGS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) -o $(OUT_NAME)

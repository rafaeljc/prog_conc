CC = gcc

PRE_OBJS = main.c tarefas.c controle_threads.c trata_argumentos_entrada.c
PRE_COMPILER_FLAGS = -c -O

OBJS = main.o tarefas.o controle_threads.o trata_argumentos_entrada.o
COMPILER_FLAGS = -Wall
LINKER_FLAGS = -lpthread
OUT_NAME = lab7

all: $(PRE_OBJS) $(OBJS)
	$(CC) $(PRE_OBJS) $(PRE_COMPILER_FLAGS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OUT_NAME)

CC = gcc

PRE_OBJS = main.c tarefas.c trata_argumentos_entrada.c controle_threads.c
PRE_COMPILER_FLAGS = -c -O

OBJS = main.o tarefas.o trata_argumentos_entrada.o controle_threads.o
COMPILER_FLAGS = -Wall
LINKER_FLAGS = -lpthread
OUT_NAME = lab6

all: $(PRE_OBJS) $(OBJS)
	$(CC) $(PRE_OBJS) $(PRE_COMPILER_FLAGS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OUT_NAME)

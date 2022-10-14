# Laboratório 6

## Compilando o programa
```console
make all
```

ou

```console
gcc *.c -c -O
```
```console
gcc *.o -Wall -lpthread -o lab6
```

## Usando o programa
```console
./lab6 [<num Tarefa1> <num Tarefa2> <num Tarefa3>]
```
**Observação:** Usar argumento é opcional. Mas uma vez utilizado, é necessário usar todos os três.


## Análise dos resultados
Com apenas 1 thread para cada tarefa (./lab6), a tendência de execução delas foi seguir a ordem das chamadas. A thread 0 na frente da 1 e da 2; a thread 1 na frente da 2. Ao aumentar o número de threads de cada tarefa para 3 (./lab6 3 3 3), apesar da thread 0 continuar tendo vantagem para ser a primeira a começar, fez com que não existisse mais "uma ordem" de execução das threads. Isso aconteceu porque o aumento do número de threads também aumentou a concorrência das tarefas pelo uso dos recursos da máquina, e como eles são administrados pelo sistema operacional, acarretou numa maior imprevisibilidade na ordem de execução delas. Já quando uma das tarefas dispôs da maioria das threads (./lab6 7 1 1, ./lab6 1 7 1 e ./lab6 1 1 7), tal tarefa teve um "aumento na prioridade" de execução. Em um cenário de disputa pelos recursos, possuir mais "competidores" aumentam as chances de conseguir executar sua tarefa primeiro.

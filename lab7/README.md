# Laboratório 7

## Compilando o programa
```console
make all
```

ou

```console
gcc *.c -c -O
```
```console
gcc *.o -Wall -lpthread -o lab7
```

## Usando o programa
```console
./lab7 [<num produtores> <num consumidores>]
```
**Observação:** Usar argumento é opcional. Mas uma vez utilizado, é necessário usar todos os dois.

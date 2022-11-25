# Laboratório 8

## Compilando o programa
```console
javac *.java
```

## Usando o programa
```console
java Lab8 [<num prod> <num cons>]
```
**Observação:** Usar argumento é opcional. Mas uma vez utilizado, é necessário usar todos os dois.

## Observações sobre as execuções do programa
Foram implementadas duas versões, uma utilizando apenas o *synchronized* (implementação 1) e outra utilizando o padrão básico de produdor/consumidor com *lock* e variáveis de condição, além de usar uma política de *fairness* para que o *signal* de desbloqueio libere aquele que estiver bloqueado a mais tempo (implementação 2). Ambas implementações foram executadas com os seguintes números de produtores e consumidores (respectivamente): (1, 1), (1, 3), (3, 1), (3, 3). No cenário em que há um grande desequilíbrio entre o número de produtores e consumidores, em ambas as implementações, aquele que está em maior número exibe um maior número de bloqueio de suas threads. Isso ocorre pois aquele que está em vantagem consegue acesso a seção crítica mais vezes e, na maioria dos casos, não deu tempo do outro fazer o seu papel (remover elemento de um buffer cheio ou inserir elemento em um buffer vazio). Na implementação 2, para o que estava em maioria, fez com que determinada thread conseguisse executar mais vezes que as outras. Pois, apesar da política justa de desbloqueio de threads, na maioria dos casos, quando a thread era liberada o buffer encontrava-se vazio ou cheio por causa do *starvation*. Já no cenário de equilíbrio entre o número de produtores e consumidores, o número de bloqueios foi distribuído entre os tipos de tarefa. Na implementação 2, por causa da política de desbloqueio, foi observado um número menor de bloqueio de threads e o buffer manteve um número de elementos relativamente estável durante a execução.
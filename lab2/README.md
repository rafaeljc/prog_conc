# Laboratório 2

## Compilando o programa
```console
gcc -c *.c
```
```console
gcc *.o -O -Wall
```

## Verificando a corretude da solução
Para verificar a corretude da solução gerada pelo programa, foi utilizado o WolframAlpha.

Os arquivos das matrizes utilizadas como entrada e a respectiva solução encontram-se na pasta 'ferramentas'. Já a solução do WolframAlpha, pode ser encontrada [aqui](https://www.wolframalpha.com/input?i=matrix+multiplication+calculator&assumption=%7B%22F%22%2C+%22MatricesOperations%22%2C+%22theMatrix2%22%7D+-%3E%22%7B%7B51.599998%2C40.799999%2C126.599998%7D%2C%7B223.199997%2C203.399994%2C183.600006%7D%2C%7B27.299999%2C127.199997%2C130.500000%7D%2C%7B132.000000%2C219.600006%2C30.600000%7D%7D%22&assumption=%7B%22F%22%2C+%22MatricesOperations%22%2C+%22theMatrix1%22%7D+-%3E%22%7B%7B93.900002%2C16.799999%2C211.199997%2C148.800003%7D%2C%7B78.300003%2C12.300000%2C92.699997%2C217.800003%7D%2C%7B162.300003%2C251.699997%2C126.900002%2C32.700001%7D%7D%22).

Note que a solução apresentada pelo WolframAlpha possui apenas uma casa decimal de precisão. Ao comparar as soluções, mesmo com a divergência na parte decimal dos números, podemos assumir que o programa gera uma solução correta para a multiplicação de duas matrizes.

## Avaliando o tempo de execução
Utilizando o programa disponível na pasta 'ferramentas', foram geradas duas matrizes aleatórias de tamanhos 500x500, 1000x1000 e 2000x2000. Em seguida, foram efetuadas **3 vezes** a multiplicação de matrizes cujas saídas do programa foram:

### 500x500
```console
rafael@rafael-Inspiron-5437:~/Documents/UFRJ/prog_conc/lab2$ ./a.out m500_1 m500_2 m500_3
Inicializando...
Pronto! (0.002435)
Calculando produto das matrizes...
Pronto! (0.979423)
Finalizando...
Pronto! (0.002284)
-- RESUMO:
Inicialização: 0.25%
Processamento: 99.52%
Finalização: 0.23%
rafael@rafael-Inspiron-5437:~/Documents/UFRJ/prog_conc/lab2$ ./a.out m500_1 m500_2 m500_3
Inicializando...
Pronto! (0.002302)
Calculando produto das matrizes...
Pronto! (0.967315)
Finalizando...
Pronto! (0.002114)
-- RESUMO:
Inicialização: 0.24%
Processamento: 99.55%
Finalização: 0.22%
rafael@rafael-Inspiron-5437:~/Documents/UFRJ/prog_conc/lab2$ ./a.out m500_1 m500_2 m500_3
Inicializando...
Pronto! (0.001937)
Calculando produto das matrizes...
Pronto! (1.257509)
Finalizando...
Pronto! (0.010061)
-- RESUMO:
Inicialização: 0.15%
Processamento: 99.05%
Finalização: 0.79%
```

### 1000x1000
```console
rafael@rafael-Inspiron-5437:~/Documents/UFRJ/prog_conc/lab2$ ./a.out m1000_1 m1000_2 m1000_3
Inicializando...
Pronto! (0.007905)
Calculando produto das matrizes...
Pronto! (10.210210)
Finalizando...
Pronto! (0.037005)
-- RESUMO:
Inicialização: 0.08%
Processamento: 99.56%
Finalização: 0.36%
rafael@rafael-Inspiron-5437:~/Documents/UFRJ/prog_conc/lab2$ ./a.out m1000_1 m1000_2 m1000_3
Inicializando...
Pronto! (0.007670)
Calculando produto das matrizes...
Pronto! (8.625021)
Finalizando...
Pronto! (0.014396)
-- RESUMO:
Inicialização: 0.09%
Processamento: 99.74%
Finalização: 0.17%
rafael@rafael-Inspiron-5437:~/Documents/UFRJ/prog_conc/lab2$ ./a.out m1000_1 m1000_2 m1000_3
Inicializando...
Pronto! (0.006867)
Calculando produto das matrizes...
Pronto! (8.731176)
Finalizando...
Pronto! (0.039927)
-- RESUMO:
Inicialização: 0.08%
Processamento: 99.47%
Finalização: 0.45%
```

### 2000x2000
```console
rafael@rafael-Inspiron-5437:~/Documents/UFRJ/prog_conc/lab2$ ./a.out m2000_1 m2000_2 m2000_3
Inicializando...
Pronto! (0.030535)
Calculando produto das matrizes...
Pronto! (119.061488)
Finalizando...
Pronto! (0.055438)
-- RESUMO:
Inicialização: 0.03%
Processamento: 99.93%
Finalização: 0.05%
rafael@rafael-Inspiron-5437:~/Documents/UFRJ/prog_conc/lab2$ ./a.out m2000_1 m2000_2 m2000_3
Inicializando...
Pronto! (0.030566)
Calculando produto das matrizes...
Pronto! (119.323435)
Finalizando...
Pronto! (0.064930)
-- RESUMO:
Inicialização: 0.03%
Processamento: 99.92%
Finalização: 0.05%
rafael@rafael-Inspiron-5437:~/Documents/UFRJ/prog_conc/lab2$ ./a.out m2000_1 m2000_2 m2000_3
Inicializando...
Pronto! (0.025904)
Calculando produto das matrizes...
Pronto! (119.751132)
Finalizando...
Pronto! (0.058010)
-- RESUMO:
Inicialização: 0.02%
Processamento: 99.93%
Finalização: 0.05%
```

## Ganho de desempenho
Pelos dados obtidos, percebe-se que a multiplicação das matrizes é responsável por mais de 99% do tempo de execução do programa. Dado a natureza do problema e o impacto que ele traz para o tempo de execução, seria interessante verificar o ganho teórico de desempenho caso fosse implementado uma versão concorrente do programa. Para isso, usemos a *Lei de Amdahl* para cada um dos casos testados. Mas, antes de tudo, calculemos o tempo médio para cada etapa de execução do programa.
### 500x500
- Inicialização: 0.002224
- Processamento: 1.068082
- Finalização: 0.004819

### 1000x1000
- Inicialização: 0.007480
- Processamento: 9.188802
- Finalização: 0.030442

### 2000x2000
- Inicialização: 0.029001
- Processamento: 119.378685
- Finalização: 0.059459

Após aplicar a lei, considerando o uso de **4 fluxos de execução** na versão concorrente, foram encontrados os seguintes valores:

- 500x500: 1.075125 / 0.2740635 = 3.922904728
- 1000x1000: 9.226724 / 2.3351225 = 3.9512805
- 2000x2000: 119.467145 / 29.93313125 = 3.991134239

Pelo resultado, conclui-se que teríamos uma execução pelo menos 3.92 vezes mais rápida se for utilizada uma versão concorrente.

# Laboratório 3

## Compilando o programa
```console
gcc -c *.c
```
```console
gcc *.o -O -Wall -lpthread
```

## Avaliando o tempo de execução
Utilizando o programa disponível na pasta 'ferramentas', foram geradas duas matrizes aleatórias de tamanhos 500x500, 1000x1000 e 2000x2000. Em seguida, foram efetuadas **3 vezes** a multiplicação de matrizes cujas saídas do programa foram:

### 500x500
```console
rafael@rafael-Inspiron-5437:~/Documents/UFRJ/prog_conc/lab3$ ./a.out m500_1 m500_2 m500_3
Pronto!
--- RESUMO
Número de threads:      2
Matriz (saída):         500 x 500
- Tempo de Execução
Inicialização:          0.001703
Processamento:          0.500284
Finalização:            0.004523
Total:                  0.506511
rafael@rafael-Inspiron-5437:~/Documents/UFRJ/prog_conc/lab3$ ./a.out m500_1 m500_2 m500_3
Pronto!
--- RESUMO
Número de threads:      2
Matriz (saída):         500 x 500
- Tempo de Execução
Inicialização:          0.001831
Processamento:          0.631908
Finalização:            0.004617
Total:                  0.638356
rafael@rafael-Inspiron-5437:~/Documents/UFRJ/prog_conc/lab3$ ./a.out m500_1 m500_2 m500_3
Pronto!
--- RESUMO
Número de threads:      2
Matriz (saída):         500 x 500
- Tempo de Execução
Inicialização:          0.002123
Processamento:          0.538390
Finalização:            0.002053
Total:                  0.542567
```

### 1000x1000
```console
rafael@rafael-Inspiron-5437:~/Documents/UFRJ/prog_conc/lab3$ ./a.out m1000_1 m1000_2 m1000_3
Pronto!
--- RESUMO
Número de threads:      2
Matriz (saída):         1000 x 1000
- Tempo de Execução
Inicialização:          0.007921
Processamento:          4.370522
Finalização:            0.015332
Total:                  4.393776
rafael@rafael-Inspiron-5437:~/Documents/UFRJ/prog_conc/lab3$ ./a.out m1000_1 m1000_2 m1000_3
Pronto!
--- RESUMO
Número de threads:      2
Matriz (saída):         1000 x 1000
- Tempo de Execução
Inicialização:          0.006666
Processamento:          4.355818
Finalização:            0.007136
Total:                  4.369619
rafael@rafael-Inspiron-5437:~/Documents/UFRJ/prog_conc/lab3$ ./a.out m1000_1 m1000_2 m1000_3
Pronto!
--- RESUMO
Número de threads:      2
Matriz (saída):         1000 x 1000
- Tempo de Execução
Inicialização:          0.006988
Processamento:          4.373841
Finalização:            0.014721
Total:                  4.395550
```

### 2000x2000
```console
rafael@rafael-Inspiron-5437:~/Documents/UFRJ/prog_conc/lab3$ ./a.out m2000_1 m2000_2 m2000_3
Pronto!
--- RESUMO
Número de threads:      2
Matriz (saída):         2000 x 2000
- Tempo de Execução
Inicialização:          0.028522
Processamento:          61.611948
Finalização:            0.051534
Total:                  61.692004
rafael@rafael-Inspiron-5437:~/Documents/UFRJ/prog_conc/lab3$ ./a.out m2000_1 m2000_2 m2000_3
Pronto!
--- RESUMO
Número de threads:      2
Matriz (saída):         2000 x 2000
- Tempo de Execução
Inicialização:          0.024052
Processamento:          61.235706
Finalização:            0.067294
Total:                  61.327053
rafael@rafael-Inspiron-5437:~/Documents/UFRJ/prog_conc/lab3$ ./a.out m2000_1 m2000_2 m2000_3
Pronto!
--- RESUMO
Número de threads:      2
Matriz (saída):         2000 x 2000
- Tempo de Execução
Inicialização:          0.023729
Processamento:          59.469345
Finalização:            0.078137
Total:                  59.571212
```

Dos dados obtidos, calculemos o valor médio do tempo de execução de cada parte do programa.
### 500x500
- Inicialização: 0.001885667
- Processamento: 0.556860667
- Finalização: 0.003731

### 1000x1000
- Inicialização: 0.007191667
- Processamento: 4.366727
- Finalização: 0.012396333

### 2000x2000
- Inicialização: 0.025434333
- Processamento: 60.772333
- Finalização: 0.065655

## Ganho de desempenho
Agora, apliquemos a *Lei de Amdahl*, para cada um dos casos testados, para descobrir o ganho real ao utilizar uma solução concorrente e o comparemos com os valores teóricos calculados no laboratório anterior.

- 500x500: 1.075125 / 0.562477334 = 1.911410354 (teórico: 1.986983537)
- 1000x1000: 9.226724 / 4.386315 = 2.103525169 (teórico: 1.991813611)
- 2000x2000: 119.467145 / 60.863422333 = 1.962872616 (teórico: 1.998520186)

Podemos verificar que o ganho real ficou próximo do estimado anteriormente. Tal resultado já era esperado pois a fórmula não leva em consideração o tempo extra para criar os novos fluxos de execução além de outros fatores como a alocação de recursos feita pelo sistema operacional ou a concorrência de outros processos que estejam sendo executados na máquina. No caso da matriz 1000x1000, o valor real ficou acima do estimado provavelmente porque foram feitas apenas 3 medições para calcular os valores médios.

## Processador utilizado
[Intel(R) Core(TM) i7-4500U CPU @ 1.80GHz](https://www.intel.com.br/content/www/br/pt/products/sku/75460/intel-core-i74500u-processor-4m-cache-up-to-3-00-ghz/specifications.html)
- Número de núcleos: 2
- Nº de threads: 4

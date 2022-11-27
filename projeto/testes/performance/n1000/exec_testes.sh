#!/bin/bash
n=50
echo "Efetuando testes versão sequencial..."
for i in $(seq 1 $n); do
  ./gauss-jacobi_seq A b >> out_seq.txt
done
for t in 2 3 4 5; do
  echo "Efetuando testes versão concorrente ($t threads)..."
  for i in $(seq 1 $n); do
    ./gauss-jacobi A b -num_threads $t >> out_$t.txt
  done
done

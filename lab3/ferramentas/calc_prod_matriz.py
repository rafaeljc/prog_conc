import sys
import ctypes
import struct
import numpy as np

def le_matriz(nome_arquivo):
    int_tam = ctypes.sizeof(ctypes.c_int)
    float_tam = ctypes.sizeof(ctypes.c_float)
    with open(nome_arquivo, 'rb') as file:
        num_linhas = file.read(int_tam)
        num_linhas = struct.unpack('i', num_linhas)[0]
        num_colunas = file.read(int_tam)
        num_colunas = struct.unpack('i', num_colunas)[0]
        num_elementos = num_linhas*num_colunas
        matriz = file.read(num_elementos*float_tam)
        matriz = struct.unpack('f'*num_elementos, matriz)
        matriz = np.array(matriz).reshape(num_linhas, num_colunas)
    return matriz

def main(argv):    
    m1 = le_matriz(argv[0])
    m2 = le_matriz(argv[1])
    m3 = le_matriz(argv[2])
    prod = m1@m2
    print('C')
    print(m3)
    print('Numpy')
    print(prod)
    check = np.allclose(m3, prod)
    print(f'Matrizes são "iguais"? {check}')
    return

if __name__ == '__main__':
    main(sys.argv[1:])

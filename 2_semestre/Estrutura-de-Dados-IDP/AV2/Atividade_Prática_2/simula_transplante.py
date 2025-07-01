import ctypes
import random
import time

lib = ctypes.CDLL('./libtransplante_fila.so')

lib.criaFila.restype = ctypes.POINTER(ctypes.c_void_p)
lib.enfileira.argtypes = [ctypes.POINTER(ctypes.c_void_p), ctypes.c_int, ctypes.c_char_p]
lib.desenfileira.argtypes = [ctypes.POINTER(ctypes.c_void_p)]
lib.desenfileira.restype = ctypes.POINTER(ctypes.c_void_p)
lib.imprimeFila.argtypes = [ctypes.POINTER(ctypes.c_void_p)]

fila = lib.criaFila()

def simulacao_transplante(num_operacoes):
    tipos_transplante = [b"CORACAO", b"CORNEA", b"MEDULA"]
    for _ in range(num_operacoes):
        operacao = random.choice(["inserir", "remover"])
        if operacao == "inserir":
            idade = random.randint(20, 90)
            tipo = random.choice(tipos_transplante)
            lib.enfileira(fila, idade, tipo)
        else:
            removido = lib.desenfileira(fila)
            if removido:
                print("Paciente removido da fila.")

simulacao_transplante(100)

print("\nFila final de transplantes (por prioridade de idade):")
lib.imprimeFila(fila)

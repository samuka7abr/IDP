import numpy as np

def inserir():
    valores = input("Digite os valores separados por espaço: ")
    dados = valores.split()
    dados = [float(valor) for valor in dados]  
    array = np.array(dados)
    array.sort()
    return array

def removerMAXMIN(array):
    if len(array) > 2:
        array = array[1:-1]
    else:
        print("O array deve ter mais de 2 elementos para remover o máximo e o mínimo.")
    return array

def media(array):
    if len(array) > 0:
        media = np.mean(array)
        return f"Média Aparada: {media}"
    else:
        return "O array está vazio, não é possível calcular a média."

array = inserir()
array = removerMAXMIN(array)
resultado_media = media(array)
print(resultado_media)

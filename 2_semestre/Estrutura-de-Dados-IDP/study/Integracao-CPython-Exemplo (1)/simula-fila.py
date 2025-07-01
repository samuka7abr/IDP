'''import random                           # gerador de números aleatórios
import simpy                   # biblioteca de simulação

TEMPO_MEDIO_CHEGADAS    = 10.0          # tempo médio entre chegadas sucessivas de clientes
TEMPO_MEDIO_ATENDIMENTO = 30.0           # tempo médio de atendimento no servidor

tempoEsperaFila  = []
tempoAtendimento = []
tempoTotal       = []

tempoInsercaoFila = []
tempoRemocaoFila  = []

def distribuicoes(tipo):
    # função que armazena as distribuições 
    # utilizadas no modelo
    return {
        'chegadas':     random.gauss(TEMPO_MEDIO_CHEGADAS, 2),
        'chegadasexpo': random.expovariate(1.0/TEMPO_MEDIO_CHEGADAS),
        'atendimento1': random.gauss(TEMPO_MEDIO_ATENDIMENTO, 2),
        'atendimento2': random.triangular(TEMPO_MEDIO_ATENDIMENTO-1,TEMPO_MEDIO_ATENDIMENTO+1,TEMPO_MEDIO_ATENDIMENTO),
        'atendimento3': random.uniform(TEMPO_MEDIO_ATENDIMENTO-1, TEMPO_MEDIO_ATENDIMENTO+1),
    }.get(tipo, 0.0)

def atendimentoServidor(env, hora_chegada, nome, id, fila):
    global tempoEsperaFila, tempoAtendimento, tempoTotal, tempoInsercaoFila, tempoRemocaoFila
    # armazena o instante de chegada do cliente ao posto1
    
    enfileira = env.now
    # função que ocupa o servidor e realiza o atendimento
    # solicita o recurso enfileirar
    lib.enfileira(fila, id)   
    tempoInsercaoFila.append(env.now - enfileira)
    
    # calcula o tempo em fila na chegada
    tempoEsperaFila.append(env.now - hora_chegada)      
                 
    # inicia o atendimento
    inicio_atendimento = env.now
    print(f"{env.now:.2f} Servidor inicia o atendimento do {nome}")
    # aguarda um tempo de atendimento exponencialmente distribuído
    yield env.timeout(distribuicoes('atendimento1'))
    
    desenfileira = env.now
    valor = lib.desenfileira(fila)
    tempoRemocaoFila.append(env.now - desenfileira)
    print(f"{env.now:.2f} Servidor termina o atendimento do {nome}")
    
    tempoAtendimento.append(env.now - inicio_atendimento)
    tempoTotal.append(env.now - hora_chegada)

def geraChegadas(env, nome, numeroMaxChegadas, fila):
    # função que cria chegadas de entidades no sistema
    id              = 0
    ultima_chegada  = 0
    while (id < numeroMaxChegadas):
        # aguardo um intervalo de tempo normalmente distribuído
        hora_chegada = env.now
        yield env.timeout(distribuicoes('chegadasexpo'))
        id           += 1
        tempo_entre_chegadas = hora_chegada - ultima_chegada
        print(f"{nome} {id} chega em: {env.now:.2f}; tempo entre chegadas: {tempo_entre_chegadas:.2f} ")
        ultima_chegada = hora_chegada
        
        nome_id = nome + " " + str(id)
        
        env.process(atendimentoServidor(env, hora_chegada, nome_id, id, fila)) 

import ctypes

# Carregar a biblioteca compartilhada
lib = ctypes.CDLL('./libfila.so')

# Definir tipos de retorno e argumentos das funções
lib.criaFila.restype = ctypes.POINTER(ctypes.c_void_p)
lib.enfileira.argtypes = [ctypes.POINTER(ctypes.c_void_p), ctypes.c_int]
lib.desenfileira.argtypes = [ctypes.POINTER(ctypes.c_void_p)]
lib.desenfileira.restype = ctypes.c_int
lib.imprimeFila.argtypes = [ctypes.POINTER(ctypes.c_void_p)]

# Criar uma fila
fila = lib.criaFila()

# Configuração da simulação
random.seed(random.randint(0,1000))
env = simpy.Environment()

numClientes = 100
# incia processo de geração de chegadas
env.process(geraChegadas(env, nome="Cliente", numeroMaxChegadas=numClientes, fila=fila)) 
env.run()

# Mostrar a fila final
lib.imprimeFila(fila)

env.run(until=2400)         # executa o modelo por x segundos


import statistics as st
import matplotlib.pyplot as plt 
import seaborn as sns
import pandas as pd

data = {
    'Categoria':    ['Tempo na Fila']*len(tempoEsperaFila) + 
                    ['Tempo Atendimento']*len(tempoAtendimento) + 
                    ['Tempo Total']*len(tempoTotal),
    'Tempo':    tempoEsperaFila +
                    tempoAtendimento +
                    tempoTotal
}

df = pd.DataFrame(data)

# Criar o boxplot
plt.figure(figsize=(10, 6))
sns.boxplot(x='Categoria', y='Tempo', data=df)

# Adicionar título e rótulos
plt.title('Tempos de Fila, Atendimento e Total')
plt.xlabel('Categoria')
plt.ylabel('Tempo')

# Mostrar o gráfico
plt.show()


sns.histplot(data=df, x='Tempo', hue='Categoria', element='step', stat='density', common_norm=False, bins=20)

# Adicionar título e rótulos
plt.title('Tempos de Fila, Atendimento e Total')
plt.xlabel('Categoria')
plt.ylabel('Tempo')

# Mostrar o gráfico
plt.show()'''
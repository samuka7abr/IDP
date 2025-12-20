opcoes = {0, 1}

while True:
    try:
        botaoA = int(input("Escolha entre 0 e 1 para o botão A: "))
        botaoB = int(input("Escolha entre 0 e 1 para o botão B: "))
    except ValueError:
        print("valores inválidos")
        continue

    if botaoA not in opcoes or botaoB not in opcoes:
        print("só pode valores entre 0 e 1")
        continue

    if not (bool(botaoA) == bool(botaoB)):
        print("led ligado")
        break
    elif botaoA == 1 and botaoB == 1:
        print("ambos pressionados: use apenas um")
    else:
        print("nenhum pressionado: tente novamente")

opcoes = {0,1}

while True:
    try:
        botaoA = int(input("Escolha entre 0 e 1: "))
        botaoB = int(input("Escolha entre 0 e 1: "))
    except ValueError:
        print("valores inválidos")
        continue

    if botaoA not in opcoes or botaoB not in opcoes:
        print("só pode valores entre 0 e 1")
        break
    
    if botaoA or botaoB :
        print("led ligado")
        break
    else:
        print("botão não ligou!!")
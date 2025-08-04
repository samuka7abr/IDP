# Snake Game - Projeto Final de Algoritmos e Lógica de Programação

## Descrição
Este é um jogo da Cobrinha (Snake Game) desenvolvido em **C** como projeto final da disciplina de **Algoritmos e Lógica de Programação** no primeiro semestre do **IDP**. O jogo utiliza conceitos fundamentais da programação, como manipulação de arquivos, laços de repetição, estruturas condicionais e manipulação de entrada/saída no terminal.

## Funcionalidades
- Movimentação da cobrinha pelo tabuleiro
- Crescimento ao coletar frutas
- Sistema de pontuação
- Salvamento de scores em arquivo (`scores.txt`)
- Exibição dos 10 melhores scores
- Controle de jogo responsivo no terminal

## Controles
- `W` - Mover para cima
- `S` - Mover para baixo
- `A` - Mover para a esquerda
- `D` - Mover para a direita
- `X` - Finalizar o jogo

## Como Compilar e Executar
### Compilar:
```sh
gcc jogo.c -o jogo
```
### Executar:
```sh
./jogo
```

## Estrutura do Projeto
- `jogo.c` - Arquivo principal do jogo
- `scores.txt` - Armazena as pontuações dos jogadores

## Requisitos
- Compilador **GCC**
- Sistema operacional baseado em **Linux** (para compatibilidade total)

## Observações
Este jogo foi desenvolvido como um projeto acadêmico e tem como objetivo demonstrar a aplicação prática dos conceitos aprendidos ao longo da disciplina. Melhorias futuras podem incluir:
- Implementação de colisão mais avançada
- Interface gráfica
- Ajustes na manipulação de entrada para sistemas Windows

## Autor
**Samuel Abrão** - Desenvolvedor e estudante de Engenharia de Software no **IDP**

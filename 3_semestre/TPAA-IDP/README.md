# Técnicas de Programação e Análise de Algoritmos - TPAA 🧠⚙️

Este repositório contém todas as implementações desenvolvidas ao longo da disciplina de **Técnicas de Programação e Análise de Algoritmos**, cursada no IDP.

## Conteúdos abordados 📚

A disciplina envolveu a prática e compreensão de algoritmos fundamentais para resolução de problemas computacionais, passando por:

- 🧮 **Bitwise**
- 🧵 **Estruturas de Dados**
- 🔍 **Busca Binária**
- 📊 **Algoritmos de Ordenação**
- 🌳 **Árvores**
- ⛰️ **Heaps**
- 🧩 **Hashes**
- 🕸️ **Grafos**:
- 🧠 **Programação Dinâmica (DP)**

---

## Estrutura do Projeto 🗂️
```bash
.
├── A1
│   ├── listas_casa
│   └── listas_sala
├── A2
│   ├── listas_casa
│   └── listas_sala
├── comandos
│   ├── prova
│   │   └── ScriptsPROVA
│   └── ScriptsDiaADia
├── slides
└── study
```

- `comandos/` → contém um **executável** que automatiza a criação da estrutura de pastas e arquivos (incluindo scripts) igual à usada neste repositório.

#### 🛠️ Scripts disponíveis

Dentro da pasta [`comandos/`](comandos), você encontrará uma série de **scripts utilitários** que auxiliam no fluxo de trabalho da disciplina:

| Script         | Descrição                                                                 |
|----------------|---------------------------------------------------------------------------|
| `gerador.sh`   | Cria a estrutura de pastas e arquivos igual à deste projeto (com scripts prontos). |
| `exclui.sh`    | Remove arquivos executáveis com nome `exec` da estrutura.                 |
| `lista.sh`     | Cria a estrutura padrão para questões de listas: `arq.cpp`, `args/input`, `args/expected`. |
| `run.sh`       | Executa os programas utilizando arquivos de entrada e compara com a saída esperada. |
| `commit.sh`    | Automatiza e padroniza as mensagens de commit.                            |

#### 📁 Pasta `prova/`

Contém **versões simplificadas** dos scripts `lista.sh` e `run.sh`, adaptadas para uso rápido em avaliações e provas.

- Para rodar o script de build (assim como os outros, só  muda o nome), execute esse comando:
```bash
chmod +x comandos/gerador.sh
./comandos/gerador.sh
```

- Caso use os scripts, altere-os para o contexto da sua máquina (script.sh, exclui.sh)
## Clonando o repositório 📥
```bash
git clone https://github.com/samuka7abr/TPAA-IDP.git
```

## Autor ✍️
Samuel Abrão
github.com/samuka7abr

**Instituto de Desenvolvimento e Pesquisa (IDP)**

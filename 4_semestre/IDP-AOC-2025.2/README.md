# IDP-AOC-2025.2

### subir o docker:
```bash
docker build -t risc-v-dev .
``` 

### fluxo:

```bash
# 1. Criar estrutura de lista
./_comandos/lista.sh 01
# ↓
# Cria pasta A1/lista01/ com Makefile e pasta build/

# 2. Escrever código ASM
# ↓
# Criar arquivo 01.s com código RISC-V assembly

# 3. Executar código
./_comandos/run.sh
# ↓
# Solicita número da lista (ex: 01)
# ↓
# Solicita número do exercício (ex: 01)
# ↓
# Docker executa: make run
# ↓
# riscv64-linux-gnu-as compila .s → .o
# ↓
# riscv64-linux-gnu-ld linka .o → executável
# ↓
# qemu-riscv64 executa o binário RISC-V
``` 

## trabalho aoc – vm stack e rotinas de string (risc-v)

### objetivo
- **vm stack (listaTrabVM)**: implementar e demonstrar uma mini máquina virtual baseada em pilha, com instruções simples (push, add, sub, print, jz, halt) e dois programinhas exemplo.
- **strings (listaTrabStrings)**: implementar rotinas básicas de manipulação de strings (`strlen`, `strcpy`, `strcmp`, `strcat`, `strncmp`) em assembly RISC‑V e testar a partir de um `main.c`.

### como compilar e rodar
- requisitos locais: `riscv64-linux-gnu-*` e `qemu-riscv64` (ou usar o container do projeto).

1) vm (A1/listaTrabVM)
```bash
cd A1/listaTrabVM
make clean && make TARGET=cod run
```
- para escolher o programa da vm: editar `cod.s` em `_start` e apontar `la s0, prog_um` (soma e printa 42) ou `la s0, prog_dois` (laço infinito com salto condicional).

2) strings (A1/listaTrabStrings)
```bash
cd A1/listaTrabStrings
make clean && make run  # ou: make && qemu-riscv64 ./build/cod
```
- o `Makefile` compila `cod.s` e `main.c` estaticamente e executa com o `qemu-riscv64`.

3) usando o script do repositório
```bash
./_comandos/run.sh
# exemplo de entradas:
# Num lista: TrabVM   | Ex: cod
# Num lista: TrabStrings | Ex: cod
```

### vm stack (arquivos em A1/listaTrabVM)
- `cod.s` contém:
  - vm principal: `vm_run` com loop de fetch/decode/execute.
  - pilha em memória `.bss` (`stack_area`).
  - instruções (opcode, operando) armazenadas na `.data` (`prog_um`, `prog_dois`).
  - `print_int`: rotina de impressão decimal com `ecall`.

- opcodes implementados:
  - **1 PUSH n**: empilha o imediato `n` (word).
  - **2 ADD**: desempilha `a` e `b`, empilha `a+b`.
  - **3 SUB**: desempilha `a` e `b`, empilha `a-b`.
  - **4 PRINT**: imprime o topo da pilha como inteiro e newline.
  - **5 JZ off**: desempilha cond; se zero, soma `off` ao `pc` (salto relativo).
  - **6 HALT**: restaura registradores e retorna ao sistema.

- programas de exemplo:
  - `prog_um`: `push 2; push 40; add; print; halt` → saída: `42`.
  - `prog_dois`: demonstra `jz` com laço infinito.

- fluxo de execução:
  - `_start` configura base do código e pilha da vm, chama `vm_run` com (code_base, stack_base, stack_words).
  - `vm_run` lê `opcode`/`operando`, salta para o handler (ex.: `op_add`), atualiza `pc` e repete.

### strings (arquivos em A1/listaTrabStrings)
- `cod.s` implementa:
  - `strlen(s)`: varre bytes até `\0` e retorna o comprimento.
  - `strcpy(dst, src)`: copia byte a byte incluindo `\0` e retorna `dst`.
  - `strcmp(a, b)`: compara bytes; retorna diferença no primeiro ponto de divergência ou `0` se iguais.
  - `strcat(dst, src)`: avança até o `\0` de `dst` e copia `src` (inclui `\0`).
  - `strncmp(a, b, n)`: compara até `n` bytes ou até `\0`.

- `main.c` (teste): chama cada rotina e imprime resultados para validação.

### roteiro rápido de apresentação (5–7 min)
1) contexto (30s)
   - objetivo: demonstrar vm simples em pilha e rotinas de string em RISC‑V.
2) vm (3–4 min)
   - mostrar `opcodes` e a estrutura do loop (`vm_loop`).
   - destacar `PUSH/ADD/SUB/PRINT/JZ/HALT` e a pilha `stack_area`.
   - escolher `prog_um`, rodar, mostrar saída `42`.
   - opcional: trocar para `prog_dois` e explicar o comportamento do `JZ`.
3) strings (2–3 min)
   - abrir `cod.s`: explicar brevemente cada rotina.
   - rodar `make run` e comentar as saídas do `main.c` (comparações e concatenação).
4) fechamento (30s)
   - pontos fortes: clareza dos handlers da vm, rotinas de string lineares e diretas.
   - possíveis extensões: mais opcodes (mul/div/call/ret), tratamento de erros e testes extras.

### problemas comuns e soluções
- aviso "newline inserted" ao montar: garantir newline no fim do arquivo `.s`.
- label inexistente em `_start`: ajustar para `prog_um` ou `prog_dois`.
- toolchain ausente: rodar via container (script `run.sh`).

### anexos úteis
- `A1/listaTrabVM/cod.s`: vm stack e exemplos.
- `A1/listaTrabStrings/cod.s`: rotinas de string.
- `A1/listaTrabStrings/main.c`: testes.
- `A1/listaTrabStrings/Makefile`: build e run com qemu.



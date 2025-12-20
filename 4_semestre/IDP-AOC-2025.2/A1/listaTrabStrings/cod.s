    .text
    .globl strlen
strlen:
    mv t0, a0            # t0 = ptr
    li t1, 0             # t1 = len
1:
    lbu t2, 0(t0)        # carrega byte
    beq t2, x0, 2f       # se \0, fim
    addi t1, t1, 1       # len++
    addi t0, t0, 1       # avanca ptr
    j 1b                 # loop
2:
    mv a0, t1            # retorna len
    ret

    .globl strcpy
strcpy:
    mv t0, a0            # dst
    mv t1, a1            # src
    mv t2, a0            # guarda dst para retorno
1:
    lbu t3, 0(t1)        # byte de src
    sb t3, 0(t0)         # escreve em dst
    addi t1, t1, 1       # avanca src
    addi t0, t0, 1       # avanca dst
    bne t3, x0, 1b       # continua ate \0
    mv a0, t2            # retorna dst
    ret

    .globl strcmp
strcmp:
    mv t0, a0            # a
    mv t1, a1            # b
1:
    lbu t2, 0(t0)        # byte a
    lbu t3, 0(t1)        # byte b
    bne t2, t3, 2f       # diferente? sai
    beq t2, x0, 3f       # iguais e \0? fim
    addi t0, t0, 1       # avanca
    addi t1, t1, 1
    j 1b                 # loop
2:
    sub a0, t2, t3       # retorna diferença dos bytes
    ret
3:
    li a0, 0             # strings iguais
    ret

    .globl strcat
strcat:
    mv t0, a0            # dst
    mv t1, a1            # src
    mv t2, a0            # guarda dst
1:
    lbu t3, 0(t0)        # procura fim de dst
    beq t3, x0, 2f
    addi t0, t0, 1
    j 1b
2:
    lbu t4, 0(t1)        # copia src para o fim de dst
    sb t4, 0(t0)
    addi t0, t0, 1
    addi t1, t1, 1
    bne t4, x0, 2b       # inclui o \0
    mv a0, t2            # retorna dst
    ret

    .globl strncmp
strncmp:
    mv t0, a0            # a
    mv t1, a1            # b
    mv t2, a2            # n
    beq t2, x0, 4f       # n==0 => iguais
1:
    lbu t3, 0(t0)        # byte a
    lbu t4, 0(t1)        # byte b
    bne t3, t4, 2f       # diferente? sai
    beq t3, x0, 4f       # fim de string
    addi t0, t0, 1       # avanca
    addi t1, t1, 1
    addi t2, t2, -1      # n--
    bne t2, x0, 1b       # enquanto n>0
    li a0, 0             # iguais ate n
    ret
2:
    sub a0, t3, t4       # retorna diferença
    ret
4:
    li a0, 0             # iguais (n acabou ou \0)
    ret

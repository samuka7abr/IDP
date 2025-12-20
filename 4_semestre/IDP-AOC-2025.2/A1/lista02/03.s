    .data
    .text
    .globl main
main:
    # exemplo: carregar um valor em t0 (troque para testar)
    li t0, -5      

    # se t0 == 0 → vai pra zero
    beq t0, x0, zero

    # se t0 < 0  → vai pra neg
    blt t0, x0, neg

    # se não caiu nos casos acima → é positivo
    j pos

zero:
    # código pra caso seja zero
    li a7, 93      # syscall exit
    li a0, 0
    ecall

neg:
    # código pra caso seja negativo
    li a7, 93
    li a0, 0
    ecall

pos:
    # código pra caso seja positivo
    li a7, 93
    li a0, 0
    ecall

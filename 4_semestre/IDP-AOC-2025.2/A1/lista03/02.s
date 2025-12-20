    .data
buf: .asciz "aplaEadaxcaM akRAp" 
     .align 2 # alinha a 2^2   
n: .word 18
count: .word 0

    .text
    .globl _start

_start:
    la t0, buf # load address of buffer on t0
    la t1, n
    lw t1, 0(t1) # t1 = n
    addi t2, x0, 0 # count = 0
    addi t3, x0, 0x61 # t3 = 'a'

loop:
    beq t1, x0, done
    lbu t4, 0(t0) # load 1 byte in t4 from buf
    addi t0, t0, 1 # walk the pointer
    addi t1, t1, -1 
    bne t4, t3, loop # buf[i] == 0x61?
    addi t2, t2, 1
    jal x0, loop

done:
    la t5, count
    sw t2, 0(t5)

    .data

    .text
    .globl _start 
_start:
    
    # initialize vars
    addi t0, x0, 0
    addi t1, x0, 0
    addi t2, x0, 0

    # code
    addi t2, t2, 1
    slli t2, t2, 13 # or lui t2, t2, 0x2
    or t1, t0, t2

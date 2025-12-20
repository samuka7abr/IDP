    .data
    # global and static variables initialized

    .text
    .globl _start 
_start:
    
    # initialize vars
    addi t2, x0, 0
    addi t1, x0, 0
    lui t0, 0x4 # or addi x0, t0, imm if imm < 2^12

    # code
    lui t2, 0x4
    xor t1, t0, t2

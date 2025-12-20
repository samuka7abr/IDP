    .data
    # global and static variables initialized

    .text
    .globl _start 
_start:
    
    # initialize
    addi t0, x0, 1
    addi t1, x0, 0

    # code
    add t1, t0, t0
    add t1, t1, t0
    add t1, t1, t0

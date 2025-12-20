    .data
    # global and static variables initialized

    .text
    .globl _start 
_start:
    
    # initialize vars
    addi t4, x0, 4 # e
    addi t3, x0, 0 # d
    addi t2, x0, 2 # c
    addi t1, x0, 5 # b
    addi t0, x0, 0 # a
    
    # code
    add t0, t1, t2
    sub t3, t0, t4

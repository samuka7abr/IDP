   .data
    # global and static variables initialized

    .text
    .globl _start 
_start:
    
    # initialize vars
    addi t4, x0, 0 # f
    addi t3, x0, 2 # g
    addi t2, x0, 2 # h
    addi t1, x0, 1 # i
    addi t0, x0, 1 # j
    
    # code
    add t5, t3, t2 # t5 = g + h
    add t6, t1, t0 # t6 = i + j
    sub t4, t5, t6 # f = t5 - t6 

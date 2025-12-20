    .data
    # global and static variables initialized

    .text
    .globl _start 
_start:
    
    # initialize vars
    addi t0, x0, 0
    addi t1, x0, 0
    
    # code
    xori t1, t0, -1

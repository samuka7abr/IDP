    .data
    # global and static variables initialized

    .text
    .globl _start 
_start:
    
    # initialize vars
    addi t0, x0, 0b1010
    addi t1, x0, 0
    
    # initialize masks
    li t2, 0xAAAAAAAA
    lui t3, 0x55555
    addi t3, t3, 0x555
    
    # code
    and t4, t0, t2 # extract even bits
    srli t4, t4, 1 # shift them right
    
    and t5, t0, t3 # extract odd bits
    slli t5, t5, 1 # shift them left
    
    or t1, t4, t5 # combine both

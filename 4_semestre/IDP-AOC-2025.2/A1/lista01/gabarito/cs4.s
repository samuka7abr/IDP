    .data
    # global and static variables initialized

    .text
    .globl _start 
_start:
    
    # initialize vars
    addi t0, x0, 1
    addi t1, x0, 0
    
    # code
    andi t0, t0, 0x1 # if lsb = 1, t1 = 1, else, t1 = 0
    sltiu t1, t0, 0x1 # set t4 to 1 if t1 < 1 (1 if even, 0 if odd)

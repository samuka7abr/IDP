    	.text
	.globl _start

_start:
    li t0, 5        # b = 5
    li t1, 3        # c = 3
    li t2, 7        # e = 7

    add t3, t0, t1  # a = b + c
    sub t4, t3, t2  # d = a - e

	.data
	.text
	.globl main
main:
	li t1, 1
	
	slli t1, t1, 14

	xor t0, t0, t1

# Quadruple a number
	.data
	.text
	.globl main
main:
	li t0, 5 

	slli t1, t0, 2 # t0 = 5 registra em t1 o valor de 5 com 2x shift left

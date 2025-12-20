	.data
	.text
	.globl main
main:
	li t0, 1
	li t1, 0

	slli t0, t0, 13 # faz uma máscara com o bit 1 no 13° bit
	or t2, t1, t0 # faz um or com t1 e t0 armazenando o resultado em t2

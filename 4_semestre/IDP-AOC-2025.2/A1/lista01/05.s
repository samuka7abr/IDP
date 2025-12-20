	.data
	.text
	.globl main
	
main:
	li t0, 0b101101

	andi t1, t0, 0b111 # and retorna 1 apenas quando os dois bits são 1
	# cria uma máscara para chegar até os 3 bits mais baixos

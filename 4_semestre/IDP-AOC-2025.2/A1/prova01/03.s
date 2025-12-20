	.text
	.globl main
	.globl func

func:
	addi sp, sp, -16	# cria reserva de 16b
	sw ra, 12(sp)		# ret
	sw a0, 8(sp)		# n

	beq a0, x0, retZero	# n ==0? ret 0
	
	addi a0, a0, -1		#argumento p/ recursão
	jal ra, func		#recursividade
	lw t0, 8(sp)
	add a0, a0, t0		#n + sum_to_n(n-1)
	j ret

retZero:
	addi a0, x0, 0

ret:
	lw ra, 12(sp)
	addi sp, sp, 16		# devolve reserva
	ret


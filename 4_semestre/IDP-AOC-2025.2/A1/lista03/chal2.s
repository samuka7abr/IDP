	.data
len:	.word 6
src:	.byte 65, 66, 67, 68, 69, 70	# define valor dos bytes com "ABCDEF"
dest:	.byte 0, 0, 0, 0, 0, 0,		# espaço para 6 bytes copiados

	.text
	.globl main

main:
	la t0, src			# ponteiros para 
	la t1, dest
	la t2, len	

	lw t2, 0(t2)			# counter

loop:
	beq t2, x0, done		# se counter == 0 terminou
	
	lbu t3, 0(t0)			# carrega a 1 byte
	sb t3, 0(t1)			# escreve em dest 1 byte de src

	addi t0, t0, 1			# avança ponteiro src
	addi t1, t1, 1			# avança ponteiro dst
	addi t2, t2, -1			# decrementa contador
	
	j loop

done:
porra:
	j porra

	.data
m:	.word 2          # quantidade de registros
records:
	.word 1          # id
	.half 10          # grade
	.byte 0          # flags = 0 → soma
	.byte 0          # pad
	
	.word 2
	.half -3
	.byte 1          # flags != 0 → ignora
	.byte 0

    .word 3          # id
	.half 6          # grade
	.byte 0          # flags = 0 → soma
	.byte 0          # pad
sum: .word 0
	.text
	.globl main
main:
	la t0, records
	la t1, m
	lw t1, 0(t1)
	li t2, 0

loop:
	beq t1, x0, done  # se terminou, pula pra done
	
	lbu t3, 6(t0) # carrega as flagas
	bne t3, x0, skip  # pula a flag se ela for != 0 (avança para o próximo registro)

	lh t4, 4(t0) #carrega grade (pega 16 signed bits (lh))
	add t2, t2, t4
	
skip:
	addi t0, t0, 8  #avança para o príximop registro (8bytes)
	addi t1, t1, -1

	j loop

done:
	la t5, sum
	sw t2 0(t5)

caralho:
	j caralho

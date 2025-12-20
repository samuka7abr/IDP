.data
	.text
	.globl main

main:
	li t0, 0 # i
	li t1, 10 #condição

loop:
	bge t0, t1, end # se t0 for maior ou igual que t1 pula pra end
	
	addi, t0, t0, 1 # i++

	jal x0, loop

end:
	jal x0, end

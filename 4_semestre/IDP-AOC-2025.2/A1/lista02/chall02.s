	.data
	.text
	.globl main

main:
	li t0, 3 # i
	li t1, 10 # n
	li t2, 0 # acumulador

	bgeu t0, t1, out  # se (i >= n) ou (i < 0) fora
	# dá pra usar dois (blt e bge)


in:
	addi t2, t2, 10
	j end

out:
	addi t2, t2, 5

end:
	j end


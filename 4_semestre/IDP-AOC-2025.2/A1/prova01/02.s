	.text
	.globl removeNeg

removeNeg:
	addi t0, x0, 0 		# i
	addi t1, x0, 0 		# new_size
	beq t0, a1, end		# size = 0 ? end


loop:
	slli t2, t0, 2
	add t3, a0, t2
	lw t4, 0(t3)

	blt t4, x0, skip	#arr[i] negativo skip
	slli t5, t1, 2
	add t6, a0, t5

	sw t4, 0(t6)
	addi t1, t1, 1 		#new size++

skip: 				# literal i++
	addi t0, t0, 1
	blt t0, a1, loop
end:
	mv a0, t1		#return new size
	ret

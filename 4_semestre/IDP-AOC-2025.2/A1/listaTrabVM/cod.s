	.globl _start

	.bss
	.align 3		# alinha prox simbolos a 8bytes
stack_area:
	.space 4096		# separa pilha da VM com 1024 words de 32
print_buf:
	.space 32		# buffer pra conversao

	
	.data
prog_um:
	#PUSH, 2
	#PUSH, 40
	#ADD ,0
	#PRINT, 0
	#HALT 0
	.word 1, 2
	.word 1, 40
	.word 2, 0
	.word 4, 0
	.word 6, 0

prog_dois: 			#laço infinito
	#PUSH, 1
	#JZ, +1 		(se o topo for 0, salta uma inst)
	#JZ, -1 		(caso contrario, volta e reavalia criando  um loop)
	#HALT, 0
	.word 1, 1
	.word 5, 1
	.word 5, -1
	.word 6, 0
	
	.text
	.globl vm_run

# s0=code_base, s1=stack_base, s2=stack_words, s3=pc(instruções), s5=stack_ptr(bytes)

vm_run:
	addi sp, sp, -64 	#separa 64bytes na stack da cpu com 8 slots de 8bytes (nos registradores s)
	sd ra, 56(sp)
	sd s0, 48(sp)
	sd s1, 40(sp)
	sd s2, 32(sp)
	sd s3, 24(sp)
	sd s4, 16(sp)
	sd s5, 8(sp)
	sd s6, 0(sp)
	
	mv s0, a0
	mv s1, a1
	mv s2, a2
	li s3, 0
	mv s5, s1

vm_loop:
	slli t0, s3, 3					# t0 = pc * 8 (cada instrução ocupa 8 bytes)
	add t0, s0, t0         			# t0 = code_base + (pc<<3) (endereço da instrução atual)
	lw t1, 0(t0)            		# t1 = opcode
	lw t2, 4(t0)               		# t2 = operando (imediato ou endereço)

	li t3, 1                     	# decodificador por comparação: opcode==1 ?
	beq t1, t3, op_push
	li t3, 2                      	# opcode==2 ?
	beq t1, t3, op_add
	li t3, 3                      	# opcode==3 ?
	beq t1, t3, op_sub
	li t3, 4                      	# opcode==4 ?
	beq t1, t3, op_print
	li t3, 5                      	# opcode==5 ?
	beq t1, t3, op_jz
	li t3, 6                      	# opcode==6 ?
	beq t1, t3, op_halt

	j vm_loop

op_push:
	sw t2, 0(s5)                	# *stack_ptr = operando
	addi s5, s5, 4               	# stack_ptr += 4 empilha una word
	addi s3, s3, 1               	# pc += 1
	j vm_loop

op_add:
	addi s5, s5, -4              	# stack_ptr -= 4 (aponta para topo ocupado)
	lw t5, 0(s5)                	# t5 = b (topo)
	addi s5, s5, -4              	# stack_ptr -= 4 (penúltimo)
	lw t6, 0(s5)                	# t6 = a (penúltimo)
	add t6, t6, t5               	# t6 = a + b
	sw t6, 0(s5)                
	addi s5, s5, 4                	# stack_ptr += 4 (agora aponta ao topo livre)
	addi s3, s3, 1                	# pc += 1
    
	j vm_loop

op_sub:
	addi s5, s5, -4               	# stack_ptr -= 4
	lw   t5, 0(s5)                	# t5 = b (topo)
	addi s5, s5, -4               	# stack_ptr -= 4
	lw   t6, 0(s5)                	# t6 = a (penúltimo)
	sub  t6, t6, t5               	# t6 = a - b
	sw   t6, 0(s5)                	# escreve resultado no lugar de 'a'
	addi s5, s5, 4               	# stack_ptr += 4 (topo livre)
	addi s3, s3, 1                	# pc += 1
	j vm_loop

op_print:
	addi s5, s5, -4		# desempilha 1 word do topo
	lw a0, 0(s5)		# pega valor do topo pra passar como arg
	call print_int		# imprime inteiro com quebra de linha
	addi s3, s3, 1		# avança pc
	j vm_loop			# volta pro loop principal
op_jz:
	addi s5, s5, -4		# desempilha condicao
	lw t5, 0(s5)		# t5 = condicao (0 ou !=0)
	beqz t5, jz_take	# se for zero, aplica salto relativo
	addi s3, s3, 1		# senao, apenas avanca pc
	j vm_loop			# segue execucao
jz_take:
	add s3, s3, t2		# pc = pc + offset (relativo)
	j vm_loop			# volta pro loop
op_halt:
	ld s6, 0(sp)		# restaura s6
	ld s5, 8(sp)		# restaura s5 (ponteiro da pilha da vm)
	ld s4, 16(sp)		# restaura s4
	ld s3, 24(sp)		# restaura pc salvo
	ld s2, 32(sp)		# restaura s2 (tam pilha)
	ld s1, 40(sp)		# restaura base da pilha
	ld s0, 48(sp)		# restaura base do codigo
	ld ra, 56(sp)		# restaura retorno
	addi sp, sp, 64		# libera stack frame
	ret			# volta pro chamador

print_int:
	addi sp, sp, -48	# abre stack frame local
	sd ra, 40(sp)		# salva ra
	sd s0, 32(sp)		# salva s0
	sd s1, 24(sp)		# salva s1 (flag de sinal)
	mv s0, a0		# s0 = numero a imprimir
	beqz s0, pi_zero	# trata caso zero rapido
	slti t0, s0, 0		# checa se negativo
	beqz t0, pi_pos	# se nao for, pula
	neg s0, s0		# torna positivo
	li s1, 1		# marca que tinha sinal
	j pi_go			# segue
pi_pos:
	li s1, 0		# sem sinal
pi_go:
	la t2, print_buf	# t2 = base do buffer
	addi t3, t2, 32		# t3 = fim do buffer (cursor de escrita)
pi_loop:
	li t4, 10		# base 10
	remu t5, s0, t4	# digito = n % 10
	divu s0, s0, t4	# n /= 10
	addi t5, t5, 48	# ascii do digito
	addi t3, t3, -1	# anda cursor pra tras
	sb t5, 0(t3)		# escreve digito
	bnez s0, pi_loop	# continua enquanto tiver mais digitos
	beqz s1, pi_out	# se nao tinha sinal, sai
	addi t3, t3, -1	# espaco pro '-'
	li t6, 45		# '-'
	sb t6, 0(t3)		# escreve sinal
pi_out:
	la t2, print_buf	# recalcula fim do buffer
	addi t4, t2, 32		# t4 = fim do buffer
	li t6, 10		# '\n'
	sb t6, 0(t4)		# garante newline no fim
	sub t5, t4, t3		# len = fim - inicio
	addi t5, t5, 1		# inclui '\n'
	li a0, 1		# fd=stdout
	mv a1, t3		# ptr pro inicio do texto
	mv a2, t5		# tamanho
	li a7, 64		# write
	ecall			# syscall
	ld s1, 24(sp)		# restaura s1
	ld s0, 32(sp)		# restaura s0
	ld ra, 40(sp)		# restaura ra
	addi sp, sp, 48		# fecha frame
	ret			# retorna
pi_zero:
	la a1, zbuf		# buffer fixo "0\n"
	li a0, 1		# stdout
	li a2, 2		# tamanho 2
	li a7, 64		# write
	ecall			# syscall
	ld s1, 24(sp)		# restaura s1
	ld s0, 32(sp)		# restaura s0
	ld ra, 40(sp)		# restaura ra
	addi sp, sp, 48		# fecha frame
	ret			# retorna

	.section .rodata
zbuf:
    .ascii "0\n"

	.section .text
_start:
	la s0, prog_dois		# escolhe qual programa rodar (prog_um ou prog_dois)
	la s1, stack_area
	mv a0, s0
	mv a1, s1
	li a2, 1024
	call vm_run
	li a0, 0
	li a7, 93
	ecall

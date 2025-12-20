y	.data
	.text
	.globl main
main:

	li t1, 1
	slli t1, t1, 14     # t1 = 1 << 14 (0x4000)
	li t2, -1           # t2 = 0xFFFFFFFF
	xor t1, t1, t2      # t1 = ~0x4000
	and t0, t0, t1      # limpa o bit 14 de t0


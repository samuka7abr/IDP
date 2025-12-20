# f = (g + h) - (i + j)
    .data
    .text
    .globl main

main:
    li t0, 2 #g
    li t1, 2 #h
    li t2, 2 #i
    li t3, 2 #j


    add t4, t0, t1
    add t5, t2, t3

    sub t6, t4, t5


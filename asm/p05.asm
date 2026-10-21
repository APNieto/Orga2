; Running C with a function from asm

section .text
global op
op:
    mov eax, edi
    imul eax, eax, 3
    sub eax, esi
    ret


; Compilado con: 
; nasm -f elf64 -g -F dwarf p05.asm -o p05.o
; gcc -c -g -Wall p05c.c -o p05c.o
; gcc -g -Wall p05.o p05c.o -o p05

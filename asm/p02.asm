; 1: Introducción
; Impresión con printf



section .rodata
    fmt db "Number: %d", 10, 0

section .text
    global main
    extern printf

main:
    push rbp
    mov rbp, rsp

    ; lea rdi, [rel fmt]
    mov rdi, fmt
    mov rsi, 42
    mov eax, 0
    call printf

    mov eax, 0
    pop rbp
    ret
    

; Compile with:
; # 1. Assemble the file into an object file
; nasm -f elf64 p02.asm -o p02.o
; # 2. Link using GCC while explicitly disabling PIE
; gcc -no-pie p02.o -o p02

%define SYS_WRITE 1
%define SYS_EXIT 60
%define STDOUT 1

section .data
dq 0x0A4445464748494A
msg times 3 db "Hola pimba!", 65, 10
pim EQU 89
len EQU $ - msg

global _start
section .text
_start:
    mov rax, SYS_WRITE
    mov rdi, STDOUT
    mov rsi, msg - 8
    mov rdx, len + 8
    syscall


    mov rax, SYS_EXIT   ; Exit
    mov rdi, 0
    syscall


; 2
; Bajando a tierra - 2: llama a otra función;
; por lo q guarda volátiles en no volátiles previo al llamado (rol caller - volatile/caller-saved regs);
; antes de eso guarda lo que había en los no volátiles en el stack (rol callee - non-volatile/callee-saved regs)

; uint32_t alternate_sum_4(uint32_t x1, uint32_t x2, uint32_t x3, uint32_t x4);
; Tenemos una función simple con 4 parámetros de tipo entero no signado de 32 bits,
; que devuelve un resultado del mismo tipo: x1 - x2 + x3 - x4 = y.
;                                           edi  esi  edx  ecx
; Lo primero que tenemos que identificar es dónde vamos a encontrar estos valores,
; siempre sirve dejar un comentario en el cuerpo de la función que establezca la relación entre los registros y sus valores,
; no solo para los parámetros sino también para aquellos que usamos como variables locales.

; import of C functions
extern sumar_c
extern restar_c

section .text

global _start
; alternate_sum_4_using_c:
_start:
    ; prologue
    push rbp
    mov rbp, rsp

    ; edi, esi, edx and ecx are loaded with arguments
    ; they are all volatile/caller-saved registers and could be destroyed by a function call
    ; only edi and esi will be used in the following call,
    ; so edx and ecx will be saved in non-volatile/callee-saved registers (like ebx, r12d-r15d)
    ; prior to that, these non-volatile regs need to be saved/rescued in the stack
    ; since the caller expects to have them unchanged upon return
    push r12
    push r13
    mov r12d, edx
    mov r13d, ecx
    call restar_c   ; uses edi, esi

    mov edi, eax    ; preparing the 2 arguments for sumar_c
    mov esi, r12d   ; 
    call sumar_c

    mov edi, eax
    mov esi, r13d
    call restar_c

    ; restore the non-volatile/callee-saved regs, for use by the caller function
    pop r13
    pop r12
    pop rbp
    
    ; syscall exit
    mov rax, 60
    mov rdi, 0
    syscall
    ; ret


; Compiled with:
; nasm -f elf64 -g -F dwarf p04.asm -o p04.o
; gcc -c -g p04c.c -o p04c.o
; ld p04.o p04c.o -o p04
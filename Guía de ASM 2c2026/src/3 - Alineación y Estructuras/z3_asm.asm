extern printf

%define OFFSET_NOMBRE 8
%define SIZE_ALUMNO 24

section .rodata
print_fmt db "Nombrem!: %s", 10, 0


section .text
global print_names_alumnos

; void print_names_alumnos(alumno *a, uint32_t size, uint32_t size_alumno);
print_names_alumnos:

    ; prologue, stack pointer aligning
    push rbp
    mov rbp, rsp

    push rbx            ; Saving the non-volatile/callee-saved registers in the stack
    push r12
    push r13
    push r14

    mov r12, rdi        ; Saves the array's pointer in the stack, since it's in a volatile/caller-saved register
    mov r13, rsi        ; Saves size of array from rsi in callee-saved/non-volatile register r13
    xor rbx, rbx        ; Using non-volatile rbx as counter

    .loop:
        imul r14, rbx, SIZE_ALUMNO                   ; to produce the next array's index
        mov rsi, [r12 + r14 + OFFSET_NOMBRE]         ; Setting the second argument for printf, first format specifier:
                                       ; the char pointer to the student's name of the corresponding struct in the array
        mov rdi, print_fmt             ; Setting the first argument for printf: the string to show
        ; xor rax, rax                 ; Having rax in 0 can avoid having to align the stack to 16 bytes (line 22)
        call printf

        inc rbx
        cmp rbx, r13
        jl .loop


    pop r14             ; Restoring the non-volatile/callee-saved registers
    pop r13
    pop r12
    pop rbx

    ; epilogue
    mov rsp, rbp
    pop rbp
    ret

; Compiled with:
; nasm -f elf64 -g z3_asm.asm -o z3_asm.o
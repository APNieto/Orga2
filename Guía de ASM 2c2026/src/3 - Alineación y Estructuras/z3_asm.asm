extern printf

section .rodata
print_fmt db "Nombre!: %s", 10, 0


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
    push r15
    sub rsp, 8         ; Aligns the stack to 16 bytes

    mov r12, rdi        ; Saves the array's pointer in the stack, since it's in a volatile/caller-saved register
    mov r13, rsi        ; Saves size of array from rsi in callee-saved/non-volatile register r13
    mov r14, rdx        ; Saves the struct alumno's size to a callee-saved/non-volatile register
    xor rbx, rbx        ; Using non-volatile rbx as counter

    .loop:
        mov r15, r14                   ; Saves alumno's individual size in r15, for multiplication by counter in next line
        imul r15, rbx                  ; to produce the next array's index
        mov rsi, [r12 + r15 + 0]         ; Setting the second argument for printf, first format specifier:
                                       ; the char pointer to the student's name of the corresponding struct in the array
        mov rdi, print_fmt             ; Setting the first argument for printf: the string to show
        ; xor rax, rax                 ; Having rax in 0 can avoid having to align the stack to 16 bytes (line 22)
        call printf

        inc rbx
        cmp rbx, r13
        jl .loop


    pop r15             ; Restoring the non-volatile/callee-saved registers
    pop r14
    pop r13
    pop r12
    pop rbx

    ; epilogue
    mov rsp, rbp
    pop rbp
    ret

; Compiled with:
; nasm -f elf64 -g z3_asm.asm -o z3_asm.o
extern malloc
extern free
extern strdup

section .rodata
; Constantes y offsets declarados
REGISTRO_OFFSET_ID EQU 0
REGISTRO_OFFSET_DESCRIPCION EQU 8
REGISTRO_SIZE EQU 16

section .text
FALSE EQU 0
TRUE  EQU 1

global EJERCICIO_1_HECHO
EJERCICIO_1_HECHO: db TRUE ; Cambiar por `TRUE` para correr los tests del Ejercicio 1.

global EJERCICIO_2_HECHO
EJERCICIO_2_HECHO: db FALSE ; Cambiar por `TRUE` para correr los tests del Ejercicio 2.

; ==============================================================================
; EJERCICIO 1: procesar_registros
; uint64_t procesar_registros(registro_t* array (rdi), uint32_t len (esi), int (*criterio)(uint32_t) (rdx))
; ==============================================================================
global procesar_registros
procesar_registros:
	mov rbx, rdx       ; Guardamos puntero a función criterio en rbx
	mov r12, rdi       ; Guardamos puntero al array en r12
	mov r13d, esi      ; Guardamos longitud len en r13d

	mov rcx, 0         ; i = 0
	mov r8, 0          ; total_procesados = 0

.loop:
	cmp ecx, r13d
	jge .fin

	mov edi, [r12 + rcx*8 + REGISTRO_OFFSET_ID]

	call rbx           ; Invoca criterio(id)

	cmp eax, 1
	je .incrementar

.siguiente:
	inc rcx
	jmp .loop

.incrementar:
	inc r8             ; Suma al total
	

.fin:
	mov rax, r8
	ret


; ==============================================================================
; EJERCICIO 2: clonar_filtrados
; registro_t* clonar_filtrados(registro_t* array (rdi), uint32_t len (esi), int (*criterio)(uint32_t) (rdx), uint32_t* out_len (rcx))
; ==============================================================================
global clonar_filtrados
clonar_filtrados:
	push rbp
	mov rbp, rsp
	push rbx
	push r12
	push r13
	push r14
	push r15
	sub rsp, 8

	mov r12, rdi       ; r12 = array original
	mov r13d, esi      ; r13d = len
	mov r14, rdx       ; r14 = criterio
	mov r15, rcx       ; r15 = out_len (puntero)

	call procesar_registros
	mov [r15], rax

	cmp rax, 0 
	je .fin_clonar

	; Reservamos memoria para el nuevo array en el Heap:
	mov edi, eax
	shl rdi, 3         ; rdi = len * 8
	call malloc
	mov rbx, rax       ; rbx = puntero al nuevo array clonado

	xor ecx, ecx       ; ecx = índice i
	xor edx, edx       ; edx = índice j

.loop_clonar:
	cmp ecx, r13d
	jg .fin_clonar

	; Calcula dirección del struct original
	mov eax, ecx
	shl rax, 4         ; rax = i * 16
	lea rsi, [r12 + rax]

	; Evalúa criterio(original[i].id)
	mov edi, [rsi + REGISTRO_OFFSET_ID]
	push rcx
	push rdx
	push rsi
	call r14           ; Invoca criterio(id)
	pop rsi
	pop rdx
	pop rcx

	cmp eax, 1
	jne .avanzar

	; Copia el ID al nuevo array clonado en la posición j
	mov eax, edx
	shl rax, 4         ; rax = j * 16 
	lea rdi, [rbx + rax]
	mov r8d, [rsi + REGISTRO_OFFSET_ID]
	mov [rdi + REGISTRO_OFFSET_ID], r8d

	; Duplica la descripción con strdup
	mov rdi, [rsi + REGISTRO_OFFSET_DESCRIPCION]
	push rcx
	push rdx
	push rax
	sub rsp, 8
	call strdup
	add rsp, 8
	pop rax
	pop rdx
	pop rcx

	; Guarda el puntero retornado por strdup en el nuevo struct
	mov [rbx + rax + REGISTRO_OFFSET_DESCRIPCION], rax 

	inc edx            ; j++

.avanzar:
	inc ecx            ; i++
	jmp .loop_clonar

.fin_clonar:

	mov rax, rbx       ; Retorna el puntero al array de structs

	add rsp, 8
	pop r15
	pop r14
	pop r13
	pop r12
	pop rbx
	pop rbp
	ret

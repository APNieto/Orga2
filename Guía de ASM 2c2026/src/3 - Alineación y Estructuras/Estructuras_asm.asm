;########### ESTOS SON LOS OFFSETS Y TAMAÑO DE LOS STRUCTS
; Completar las definiciones (serán revisadas por ABI enforcer):
NODO_OFFSET_NEXT EQU 0
NODO_OFFSET_CATEGORIA EQU 8
NODO_OFFSET_ARREGLO EQU 16
NODO_OFFSET_LONGITUD EQU 24
NODO_SIZE EQU 32
LISTA_OFFSET_HEAD EQU 0
LISTA_SIZE EQU 8

PACKED_NODO_OFFSET_NEXT EQU 0
PACKED_NODO_OFFSET_CATEGORIA EQU 8
PACKED_NODO_OFFSET_ARREGLO EQU 9
PACKED_NODO_OFFSET_LONGITUD EQU 17
PACKED_NODO_SIZE EQU 21
PACKED_LISTA_OFFSET_HEAD EQU 0
PACKED_LISTA_SIZE EQU 8


;########### SECCION DE DATOS
section .data

;########### SECCION DE TEXTO (PROGRAMA)
section .text

;########### LISTA DE FUNCIONES EXPORTADAS
global cantidad_total_de_elementos
global cantidad_total_de_elementos_packed
global sumatoria_de_elementos

;########### DEFINICION DE FUNCIONES
;extern uint32_t cantidad_total_de_elementos(lista_t* lista);
;registros: lista[rdi]
sumatoria_de_elementos:
	push rbp									; Alineamiento de pila + guardado de rbp anterior
	mov rbp, rsp

	xor rax, rax								; Inicializo rax como contador
	mov r8, [rdi + LISTA_OFFSET_HEAD]			; r8: guardo el primer elemento de lista_t, un nodo_t*

	.loop1:
		mov r9, [r8 + NODO_OFFSET_ARREGLO]		; r9: guardo el puntero al arreglo del nodo actual
		mov r10, [r8 + NODO_OFFSET_LONGITUD]	; r10: guardo la longitud del arreglo
		xor rcx, rcx							; rcx: lo uso como contador de elementos internos de cada array, para saber cuándo salir del loop

		.loop2:
			add rax, [r9 + rcx * 4]				; incremento rax al contar un elemento global
			inc rcx								; incremento rcx al contar un elemento interno
			cmp rcx, r10						; comparo rcx contra la longitud del arreglo actual
			jl .loop2							; itero arreglo mientras rcx < r10 (longitud arreglo)
		
		mov r8, [r8 + NODO_OFFSET_NEXT]			; r8: guardo la dirección del siguiente nodo
		test r8, r8								; testeo si r8 no es un NULL pointer
		jnz .loop1

	pop rbp
	ret


cantidad_total_de_elementos:
	push rbp									; Alineamiento de pila + guardado de rbp anterior
	mov rbp, rsp

	xor rax, rax								; Inicializo contador general
	mov r8, [rdi]									; R8: guardo el puntero al primero nodo

	.loop1:
		mov r9, [r8 + NODO_OFFSET_ARREGLO]		; R9: guardo la base de cada arreglo
		mov r10d, [r8 + NODO_OFFSET_LONGITUD]	; R10: guardo la longitud de cada arreglo
		xor ecx, ecx								; Inicializo contador interno de cada arreglo

		test r10d, r10d							; Si la longitud es cero, ir al siguiente nodo
		jz .end_loop1

		.loop2:
			inc rax								; Conteo iterno de cada array
			inc ecx
			cmp ecx, r10d
			jl .loop2

		.end_loop1:
			mov r8, [r8 + NODO_OFFSET_NEXT]		; Busco el puntero del siguiente nodo e itero en caso que no sea nulo
			test r8, r8
			jnz .loop1

	pop rbp
	ret


; 	xor rax, rax								; Inicializo rax como contador
; 	mov r8, [rdi + LISTA_OFFSET_HEAD]			; r8: guardo el primer elemento de lista_t, un nodo_t*

	
; 	mov r8, [r8 + NODO_OFFSET_NEXT]			; r8: guardo la dirección del siguiente nodo
; 	test r8, r8								; testeo si r8 no es un NULL pointer
; 	jnz .loop1

; 	ret

;extern uint32_t cantidad_total_de_elementos_packed(packed_lista_t* lista);
;registros: lista[?]
; Versión más fácil, sin doble loop
cantidad_total_de_elementos_packed:
	push rbp
	mov rbp, rsp

	xor rax, rax
	mov r8, [rdi]

	.loop1:
		test r8, r8
		jz .endloop

		mov r9, [r8 + PACKED_NODO_OFFSET_ARREGLO]
		mov r10d, [r8 + PACKED_NODO_OFFSET_LONGITUD]
		
		add eax, r10d
		
		mov r8, [r8 + PACKED_NODO_OFFSET_NEXT]
		jmp .loop1
	
	.endloop:

	pop rbp
	ret

cantidad_total_de_elementos_packed2:
	push rbp
	mov rbp, rsp

	xor rax, rax
	mov r8, [rdi]

	.loop1:
		test r8, r8
		jz .endloop

		mov r9, [r8 + PACKED_NODO_OFFSET_ARREGLO]
		mov r10d, [r8 + PACKED_NODO_OFFSET_LONGITUD]
		test r10d, r10d
		jz .endloop1
		xor ecx, ecx

		.loop2:
			inc rax
			inc ecx
			cmp ecx, r10d
			jl .loop2

		.endloop1:
			mov r8, [r8 + PACKED_NODO_OFFSET_NEXT]
			jmp .loop1
	
	.endloop:

	pop rbp
	ret


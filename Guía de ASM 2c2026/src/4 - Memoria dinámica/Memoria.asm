extern malloc
extern free
extern fprintf

section .data

section .text

global strCmp
global strClone
global strDelete
global strPrint
global strLen

; ** String **



;  Compara dos strings en orden lexicográfico. Ver https://es.wikipedia.org/wiki/Orden_lexicografico.
;  Debe retornar:
;  0 si son iguales
; -1 si a < b
;  1 si a > b
; int32_t strCmp(char* a, char* b)
; rdi: a
; rsi: b
strCmp:
	push rbp
	mov rbp, rsp
	
	xor r8, r9	 	; Das ganze r8 auf Null setzen, da nur das unterste Byte genutzt wird
	xor r9, r9

	xor rcx, rcx
	
	.loop:
		mov r8b, [rdi + rcx]	; Speichern vom ersten ASCII Wert aus a (erstes Argument)
		mov r9b, [rsi + rcx]

		cmp r8b, r9b
		jb .smaller
		ja .greater

		; Wenn die zwei Zeichen gleich sind, den Zähler hochzählen und mit dem nächsten weitermachen
		inc rcx
		jmp .loop

	.smaller:
		mov eax, -1
		jmp .end
	.greater:
		mov eax, 1
	
	.end:
		pop rbp
		ret



; uint32_t strLen(char* a)
strLen:
	push rbp
	mov rbp, rsp

	xor rax, rax

	.loop:
		; mov sil, [rdi]
		; cmp sil, 0
		cmp [rdi], 0	; Version without usage of sil
		je .end
		inc eax
		inc rdi
		jmp .loop
	
	.end:
		pop rbp
		ret



; void strDelete(char* a)
strDelete:
	push rbp
	mov rbp, rsp

	mov r8, rdi 			; Den Zeiger in rdi in r8 kopieren, um es nach der Löschung zu freeen

	.erasing:
		cmp [r8], 0
		jz .freeing
		mov [r8], 1
		inc r8
		jmp .erasing

	.freeing:
		; mov rdi, 10
		call free


	; Prüft ob asm kann in Heap Adressen nach dem free noch schreiben --> es kann
	xor rcx, rcx
	.test_write:
		mov [rdi], 65
		inc rdi
		inc rcx
		cmp rcx, 5
		jb .test_write
	
	
	pop rbp
	ret




; char* strClone(char* a)
strClone:

	push rbp
	mov rbp, rsp

	mov r12, rdi	; Saves the source block pointer in rsi

	; Find out length of the string in the source block
	;; rdi has the source pointer
	call strLen		; Doesn't save volatile rsi here bcs I know strLen doesn't use it
	mov edi, eax
	;; edi has the size of the source string
	mov r9d, edi	; Copy the source string's size in r9d

	; Request a heap block with that size
	lea edi, [edi + 1]	; using lea instead of add or inc just to test it
	push rsi		; Saving the volatile/caller-saved rsi before function calls
	call malloc
	pop rsi			; Restoring rsi after all function calls
	;; rax has the new block's address
	mov r8, rax		; Copies the new block's address in r8

	; Copy the characters from the old block into the new block
	xor rcx, rcx	; Initialize rcx as counter
	.loop:
		mov dl, [r12]
		mov [r8], dl
		cmp ecx, r9d
		lea ecx, [ecx + 1]
		lea r12, [r12 + 1]
		lea r8, [r8 + 1]
		jbe .loop

	pop rbp
	ret


; void strPrint(char* a, FILE* pFile)
strPrint:
	ret




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

; char* strClone(char* a)
strClone:
	ret

; void strDelete(char* a)
strDelete:
	ret

; void strPrint(char* a, FILE* pFile)
strPrint:
	ret

; uint32_t strLen(char* a)
strLen:
	ret



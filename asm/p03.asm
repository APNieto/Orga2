; 2
; Bajando a tierra

; uint32_t alternate_sum_4(uint32_t x1, uint32_t x2, uint32_t x3, uint32_t x4);
; Tenemos una función simple con 4 parámetros de tipo entero no signado de 32 bits,
; que devuelve un resultado del mismo tipo: x1 - x2 + x3 - x4 = y.
; Lo primero que tenemos que identificar es dónde vamos a encontrar estos valores,
; siempre sirve dejar un comentario en el cuerpo de la función que establezca la relación entre los registros y sus valores,
; no solo para los parámetros sino también para aquellos que usamos como variables locales.

section .text

alternate_sum_4:
    mov eax, edi
    sub eax, esi
    add eax, edx
    sub eax, ecx
    ret

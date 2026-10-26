%define OFFSET_NOMBRE 0
%define OFFSET_COMISION 12
%define OFFSET_DNI 8
%define ALUMNO_SIZE 13

section .data          

section .text

funcion_que_recorre:
  ;prologo
  push RBP ;pila alineada
  mov RBP, RSP ;strack frame armado

  ;tengo en RDI un puntero al comienzo de un array de alumnos
  ;y en RSI el tamaño del array
  ;asumimos que al menos hay un elemento en el array

  XOR R8, R8 ;usamos R8 como índice en el array
  
  .ciclo:
    mov RDX, [RDI + R8 * ALUMNO_SIZE + OFFSET_NOMBRE]
    ;ALUMNO_SIZE es el tamaño del struct, por eso lo usamos para escalar el índice 
    ;OFFSET_NOMBRE es el offset del atributo nombre, así que tengo en RDX el valor del atributo nombre del alumno de índice R8
    
    mov CL, BYTE [RDI + R8 * ALUMNO_SIZE + OFFSET_COMISION] 
    ; tengo en el byte mas bajo de RCX el atributo comision
    
    mov R9D, DWORD [RDI + R8 * ALUMNO_SIZE + OFFSET_DNI] 
    ; tengo en los 32 bits menos significativos de R9 el valor del atributo dni

    INC R8 ;avanzo el índice del array
    CMP R8, RSI
    JL .ciclo

  ;epilogo
  pop RBP ;pila desalineada, RBP restaurado, RSP apuntando a la dirección de retorno
  ret
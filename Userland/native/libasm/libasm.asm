GLOBAL runInvalidOpcodeException
GLOBAL runZeroDivisionException
GLOBAL inforeg

EXTERN printRegisters

section .text

runInvalidOpcodeException:
    db 0x66, 0xFF
    ret

runZeroDivisionException:
    xor rax, rax   ; rax=0
    xor rdx, rdx   ; rdx=0
    div rdx        ; rax/rdx
    ret

inforeg:

    mov [regex + 8*0], rax
    mov [regex + 8*1], rbx
    mov [regex + 8*2], rcx
    mov [regex + 8*3], rdx
    mov [regex + 8*4], rsi
    mov [regex + 8*5], rdi
    mov [regex + 8*6], rbp
    mov [regex + 8*7], rsp
    mov [regex + 8*8], r8
    mov [regex + 8*9], r9
    mov [regex + 8*10], r10
    mov [regex + 8*11], r11
    mov [regex + 8*12], r12
    mov [regex + 8*13], r13
    mov [regex + 8*14], r14
    mov [regex + 8*15], r15

	mov rax, [rsp] ; RIP.
    mov [regex + 8*16], rax

    mov rdi, regex
	call printRegisters

    ret

section .bss
    regex: resq 17; ;reserva espacio para 18 qwords (cada registro para mostrarlos en las excepciones)
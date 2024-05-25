GLOBAL cpuVendor

section .text
	
cpuVendor:
	push rbp
	mov rbp, rsp

	push rbx

	mov rax, 0
	cpuid


	mov [rdi], ebx
	mov [rdi + 4], edx
	mov [rdi + 8], ecx

	mov byte [rdi+13], 0

	mov rax, rdi

	pop rbx

	mov rsp, rbp
	pop rbp
	ret

global RTC
global numToStr

numToStr:
		mov ebp, ebx	; guardo la direccion

        push rcx
        push rdx

		push rax		; guardo el numero


		mov rbx, 0x0
		mov rcx, 0xa	; dividendo
		mov rdx, 0x0	; resto
	len1:
		div rcx			; divido el numero por 10
		inc rbx			; aumento la longitud
		mov rdx, 0x0
		cmp rax, 0x0  	; si eax es distinto
		jne len1		; de 0, divido de nuevo

		pop rax
		mov byte [rbp+rbx], 0
		dec rbx

		cmp rbx, 10
		jae err1
	cicle1:
		div rcx
		add rdx, '0'
		mov byte [rbp+rbx], dl
		mov rdx, 0
		dec rbx
		cmp rbx, 0
		jge cicle1
		jmp fin1
	err1:
		mov rdx, [warn]
		mov [rbp], rdx
	fin1:
		mov rbx, rbp

		pop rdx
		pop rcx
		ret     ; ahora esta en ebx la dir del string

RTC:
    mov al, 0
    out 70h, al
    in ax, 71h

    mov rbx, placeholder
    call numToStr
    mov [date], rbx
    mov rax, date
    ret

section .data
    date db "--:--:--"

section .bss
    placeholder resb 64

section .rodata
	warn db "ERR", 10, 0
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

global getTime
global hexToString

; recibe en eax un numero, y deja en eax un string
hexToString:
		push rbp
		mov rbp, rsp
        push rbx
        push rcx
        push rdx
		push rax

        mov rbx, 0x10
        mov rcx, 0

    .len:
        mov rdx, 0
        div rbx
        inc rcx

        cmp rax, 0
        jne .len

    ; Ahora tengo en rcx la cantidad de digitos

        pop rax     ; recupero el numero

    .loop:
        mov rdx, 0
        div rbx

        add rdx, 0x30
        mov byte [placeholder+rcx-1], dl
        dec rcx

        cmp rax, 0
        jne .loop

	.fin:
	    pop rdx
	    pop rcx
	    pop rbx

	    mov eax, placeholder
        mov rsp, rbp
        pop rbp
        ret

getTime:
        push rbp
        mov rbp, rsp
        push rbx

        mov rax, 0

        ; horas

    .wait1:
        mov al, 0x8A           ; Register 0x0A, with NMI disabled
        out 0x70, al           ; Select register 0x0A
        in al, 0x71            ; Read the value

        test al, 0x80          ; Check if update in progress (bit 7)
        jnz .wait1             ; If bit 7 is set, wait

        xor rax, rax
        mov al, 0x04

        out 70h, al
        in al, 71h

        call hexToString
        mov bx, [rax]
        mov word [date+0x0], bx

        ; minutos

    .wait2:
        mov al, 0x8A           ; Register 0x0A, with NMI disabled
        out 0x70, al           ; Select register 0x0A
        in al, 0x71            ; Read the value

        test al, 0x80          ; Check if update in progress (bit 7)
        jnz .wait2             ; If bit 7 is set, wait

        xor rax, rax
        mov al, 0x02

        out 70h, al
        in al, 71h

        call hexToString
        mov bx, [rax]
        mov word [date+0x3], bx

        ; segundos

    .wait3:
        mov al, 0x8A           ; Register 0x0A, with NMI disabled
        out 0x70, al           ; Select register 0x0A
        in al, 0x71            ; Read the value

        test al, 0x80          ; Check if update in progress (bit 7)
        jnz .wait3             ; If bit 7 is set, wait

        xor rax, rax
        mov al, 0x00

        out 70h, al
        in al, 71h

        call hexToString
        mov bx, [rax]
        mov word [date+0x6], bx

        ; devuelvo el string en eax
        mov rax, date

    .fin:
        pop rbx
        mov rsp, rbp
        pop rbp
        ret

GLOBAL getKey

getKey:
        push rbp
        mov rbp, rsp

    .loop:
        in al, 0x64
        mov cl, al
        and al, 0x01
        cmp al, 0
        je .loop

        in al, 0x60
    .fin:
        mov rsp, rbp
        pop rbp
        ret

GLOBAL get_key_2
get_key_2:
	push 	rbp
	mov     rbp, rsp

	mov		rax, 0
  	in      al, 64h
	and		rax, 01h

	cmp		rax, 01h
	jne		get_key_end		;rax=0

	in		al, 60h

get_key_end


  	leave
  	ret

GLOBAL test_int_80h ; FUNCIONA!!!
test_int_80h:
    push 	rbp
	mov     rbp, rsp
    mov     eax, 4
    mov     ebx, 1
    mov     ecx, test_int_80h_data
    mov     edx, 1
    int     80h

    leave
    ret


;==========================================0

section .data
    date db "00:00:00", 0
    test_int_80h_data db 0x63

section .bss
    placeholder resb 2
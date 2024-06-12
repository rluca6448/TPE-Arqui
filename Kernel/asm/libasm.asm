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

GLOBAL getRTC
getRTC:
	mov rax, rdi	; recibimos por parámetro.
	out 70h, al		; 70h entrada para la informacion que quiero en 71h.
	mov rax, 0
	in al, 71h		; en al se deposita lo pedido por 70h, presente en 71h.
	ret


GLOBAL getKey
getKey:
        push 	rbp
        mov     rbp, rsp

        mov		rax, 0
        in      al, 64h
        and		rax, 01h

        cmp		rax, 01h
        jne		get_key_end		;rax=0

        in		al, 60h

    get_key_end:
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

GLOBAL inb

inb:
    ; Inputs:
    ; rdi - port address
    ; Outputs:
    ; rax - data read from the port (only the lower 8 bits will be used)
    mov dx, di    ; Move port address from rdi to dx
    in al, dx     ; Read a byte from the port specified in DX into AL
    movzx eax, al ; Zero-extend AL to EAX (clear upper bits)
    ret           ; Return from the function

GLOBAL outb

outb:
    ; Inputs:
    ; rdi - port address
    ; rsi - data to send to the port
    mov dx, di    ; Move port address from rdi to dx
    mov al, sil   ; Move data from rsi to al (sil is the lower 8 bits of rsi)
    out dx, al    ; Send the byte in AL to the port specified in DX
    ret           ; Return from the function


;==========================================0

section .data
    date db "00:00:00", 0
    test_int_80h_data db 0x63

section .bss
    placeholder resb 2
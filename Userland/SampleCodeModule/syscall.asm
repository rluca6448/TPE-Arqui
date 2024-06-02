GLOBAL syscall

section .text

%macro pushState 0
	push rbx
	push rcx
	push rdx
	push rbp
	push rdi
	push rsi
	push r8
	push r9
	push r10
	push r11
	push r12
	push r13
	push r14
	push r15
%endmacro

%macro popState 0
	pop r15
	pop r14
	pop r13
	pop r12
	pop r11
	pop r10
	pop r9
	pop r8
	pop rsi
	pop rdi
	pop rbp
	pop rdx
	pop rcx
	pop rbx
%endmacro

syscall:
    pushState
    mov     rax, rcx
    mov     rcx, rdx    ; pongo rcx
    mov     rdx, rax    ; pongo rdx
    mov     rax, rdi    ; pongo rax
    mov     rbx, rsi    ; pongo rbx

    int     80h
    popState
    ret

GLOBAL test_int_80h
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

section .data
    test_int_80h_data db 0x63 ; 0x63 es una c


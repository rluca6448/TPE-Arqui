GLOBAL syscall

section .text

syscall:
    push    rbp
    mov     rbp, rsp
    push    rbx

    mov     rax, rcx
    mov     rcx, rdx    ; pongo rcx
    mov     rdx, rax    ; pongo rdx
    mov     rax, rdi    ; pongo rax
    mov     rbx, rsi    ; pongo rbx

    int     80h

    pop     rbx
    leave
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


GLOBAL syscall
GLOBAL test_asm_in_userland

section .text

test_asm_in_userland:
    push    rbp
    mov     rbp, rsp

    leave
    ret


syscall:
    push    rbp
    mov     rbp, rsp
    push    rbx

    mov     rax, rdi
    mov     rbx, rsi
    int     80h

    pop     rbx
    leave
    ret


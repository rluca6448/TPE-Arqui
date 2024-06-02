GLOBAL runInvalidOpcodeException
GLOBAL runZeroDivisionException

section .text

;encontre los ejemplo con el chatGPT ...
runInvalidOpcodeException:
    ; Trigger an invalid opcode exception using 0x66 incorrectly
    db 0x66, 0xFF ; This sequence is undefined and will cause an exception
    ret

runZeroDivisionException:
    xor rax, rax   ; Clear RAX (the dividend)
    xor rdx, rdx   ; Clear RDX (the divisor, set to zero)
    div rdx        ; Attempt to divide RAX by RDX (which is zero)
    ret
%ifndef TEE
%define TEE

section .text
    global tee:function

tee:
        mov rax, 276
        syscall
        ret

%endif

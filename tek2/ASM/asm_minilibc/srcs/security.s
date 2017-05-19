%ifndef SECURITY
%define SECURITY

section .text
    global security:function

security:
        mov rax, 185
        syscall
        ret

%endif

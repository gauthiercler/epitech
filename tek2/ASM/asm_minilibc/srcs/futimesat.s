%ifndef FUTIMESAT
%define FUTIMESAT

section .text
    global futimesat:function

futimesat:
        mov rax, 261
        syscall
        ret

%endif

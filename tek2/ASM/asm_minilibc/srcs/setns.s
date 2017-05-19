%ifndef SETNS
%define SETNS

section .text
    global setns:function

setns:
        mov rax, 308
        syscall
        ret

%endif

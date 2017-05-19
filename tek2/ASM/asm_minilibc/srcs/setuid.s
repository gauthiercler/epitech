%ifndef SETUID
%define SETUID

section .text
    global setuid:function

setuid:
        mov rax, 105
        syscall
        ret

%endif

%ifndef GETEUID
%define GETEUID

section .text
    global geteuid:function

geteuid:
        mov rax, 107
        syscall
        ret

%endif

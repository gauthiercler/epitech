%ifndef GETDENTS
%define GETDENTS

section .text
    global getdents:function

getdents:
        mov rax, 78
        syscall
        ret

%endif

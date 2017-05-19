%ifndef GETUID
%define GETUID

section .text
    global getuid:function

getuid:
        mov rax, 102
        syscall
        ret

%endif

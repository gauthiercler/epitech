%ifndef GETRESUID
%define GETRESUID

section .text
    global getresuid:function

getresuid:
        mov rax, 118
        syscall
        ret

%endif

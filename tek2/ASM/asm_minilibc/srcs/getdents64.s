%ifndef GETDENTS64
%define GETDENTS64

section .text
    global getdents64:function

getdents64:
        mov rax, 217
        syscall
        ret

%endif

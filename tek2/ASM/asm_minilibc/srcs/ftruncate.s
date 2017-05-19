%ifndef FTRUNCATE
%define FTRUNCATE

section .text
    global ftruncate:function

ftruncate:
        mov rax, 77
        syscall
        ret

%endif

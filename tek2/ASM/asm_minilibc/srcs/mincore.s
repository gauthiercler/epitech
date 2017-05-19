%ifndef MINCORE
%define MINCORE

section .text
    global mincore:function

mincore:
        mov rax, 27
        syscall
        ret

%endif

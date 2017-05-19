%ifndef UNLINK
%define UNLINK

section .text
    global unlink:function

unlink:
        mov rax, 87
        syscall
        ret

%endif

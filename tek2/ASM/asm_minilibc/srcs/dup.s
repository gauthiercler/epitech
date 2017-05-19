%ifndef DUP
%define DUP

section .text
    global dup:function

dup:
        mov rax, 32
        syscall
        ret

%endif

%ifndef IOPERM
%define IOPERM

section .text
    global ioperm:function

ioperm:
        mov rax, 173
        syscall
        ret

%endif

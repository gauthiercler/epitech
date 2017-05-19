%ifndef IOPL
%define IOPL

section .text
    global iopl:function

iopl:
        mov rax, 172
        syscall
        ret

%endif

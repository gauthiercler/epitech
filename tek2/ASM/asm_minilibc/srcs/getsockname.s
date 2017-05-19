%ifndef GETSOCKNAME
%define GETSOCKNAME

section .text
    global getsockname:function

getsockname:
        mov rax, 51
        syscall
        ret

%endif

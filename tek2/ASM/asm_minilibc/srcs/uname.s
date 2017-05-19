%ifndef UNAME
%define UNAME

section .text
    global uname:function

uname:
        mov rax, 63
        syscall
        ret

%endif

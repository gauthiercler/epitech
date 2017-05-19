%ifndef GETTID
%define GETTID

section .text
    global gettid:function

gettid:
        mov rax, 186
        syscall
        ret

%endif

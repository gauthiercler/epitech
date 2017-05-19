%ifndef OPENAT
%define OPENAT

section .text
    global openat:function

openat:
        mov rax, 257
        syscall
        ret

%endif

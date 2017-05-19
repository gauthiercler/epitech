%ifndef READLINKAT
%define READLINKAT

section .text
    global readlinkat:function

readlinkat:
        mov rax, 267
        syscall
        ret

%endif

%ifndef PIPE2
%define PIPE2

section .text
    global pipe2:function

pipe2:
        mov rax, 293
        syscall
        ret

%endif

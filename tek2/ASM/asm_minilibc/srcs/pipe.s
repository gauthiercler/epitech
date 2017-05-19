%ifndef PIPE
%define PIPE

section .text
    global pipe:function

pipe:
        mov rax, 22
        syscall
        ret

%endif

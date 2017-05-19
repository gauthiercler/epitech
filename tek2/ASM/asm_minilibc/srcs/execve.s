%ifndef EXECVE
%define EXECVE

section .text
    global execve:function

execve:
        mov rax, 59
        syscall
        ret

%endif

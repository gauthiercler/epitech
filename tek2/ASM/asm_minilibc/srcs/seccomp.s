%ifndef SECCOMP
%define SECCOMP

section .text
    global seccomp:function

seccomp:
        mov rax, 317
        syscall
        ret

%endif

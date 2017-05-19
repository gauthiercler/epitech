%ifndef SIGALTSTACK
%define SIGALTSTACK

section .text
    global sigaltstack:function

sigaltstack:
        mov rax, 131
        syscall
        ret

%endif

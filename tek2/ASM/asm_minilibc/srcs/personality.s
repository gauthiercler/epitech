%ifndef PERSONALITY
%define PERSONALITY

section .text
    global personality:function

personality:
        mov rax, 135
        syscall
        ret

%endif

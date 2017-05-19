%ifndef SWAPON
%define SWAPON

section .text
    global swapon:function

swapon:
        mov rax, 167
        syscall
        ret

%endif

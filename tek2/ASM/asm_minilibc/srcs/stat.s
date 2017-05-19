%ifndef STAT
%define STAT

section .text
    global stat:function

stat:
        mov rax, 4
        syscall
        ret

%endif

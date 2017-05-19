%ifndef SETGROUPS
%define SETGROUPS

section .text
    global setgroups:function

setgroups:
        mov rax, 116
        syscall
        ret

%endif

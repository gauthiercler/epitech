%ifndef GETGROUPS
%define GETGROUPS

section .text
    global getgroups:function

getgroups:
        mov rax, 115
        syscall
        ret

%endif

%ifndef LSTAT
%define LSTAT

section .text
    global lstat:function

lstat:
        mov rax, 6
        syscall
        ret

%endif

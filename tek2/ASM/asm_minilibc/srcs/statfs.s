%ifndef STATFS
%define STATFS

section .text
    global statfs:function

statfs:
        mov rax, 137
        syscall
        ret

%endif

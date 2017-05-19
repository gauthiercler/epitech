%ifndef MKNOD
%define MKNOD

section .text
    global mknod:function

mknod:
        mov rax, 133
        syscall
        ret

%endif

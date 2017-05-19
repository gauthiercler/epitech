%ifndef IOCTL
%define IOCTL

section .text
    global ioctl:function

ioctl:
        mov rax, 16
        syscall
        ret

%endif

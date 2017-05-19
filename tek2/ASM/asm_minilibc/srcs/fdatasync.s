%ifndef FDATASYNC
%define FDATASYNC

section .text
    global fdatasync:function

fdatasync:
        mov rax, 75
        syscall
        ret

%endif

%ifndef MSYNC
%define MSYNC

section .text
    global msync:function

msync:
        mov rax, 26
        syscall
        ret

%endif

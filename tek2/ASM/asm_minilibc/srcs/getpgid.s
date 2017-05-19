%ifndef GETPGID
%define GETPGID

section .text
    global getpgid:function

getpgid:
        mov rax, 121
        syscall
        ret

%endif

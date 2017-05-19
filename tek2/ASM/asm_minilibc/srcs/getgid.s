%ifndef GETGID
%define GETGID

section .text
    global getgid:function

getgid:
        mov rax, 104
        syscall
        ret

%endif

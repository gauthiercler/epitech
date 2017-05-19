%ifndef GETRESGID
%define GETRESGID

section .text
    global getresgid:function

getresgid:
        mov rax, 120
        syscall
        ret

%endif

%ifndef SETRESGID
%define SETRESGID

section .text
    global setresgid:function

setresgid:
        mov rax, 119
        syscall
        ret

%endif

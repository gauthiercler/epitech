%ifndef SETGID
%define SETGID

section .text
    global setgid:function

setgid:
        mov rax, 106
        syscall
        ret

%endif

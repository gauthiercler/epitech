%ifndef SETFSGID
%define SETFSGID

section .text
    global setfsgid:function

setfsgid:
        mov rax, 123
        syscall
        ret

%endif

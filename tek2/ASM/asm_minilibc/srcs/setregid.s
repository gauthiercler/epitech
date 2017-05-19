%ifndef SETREGID
%define SETREGID

section .text
    global setregid:function

setregid:
        mov rax, 114
        syscall
        ret

%endif

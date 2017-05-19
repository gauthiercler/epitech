%ifndef WAITID
%define WAITID

section .text
    global waitid:function

waitid:
        mov rax, 247
        syscall
        ret

%endif

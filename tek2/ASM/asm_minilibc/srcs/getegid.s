%ifndef GETEGID
%define GETEGID

section .text
    global getegid:function

getegid:
        mov rax, 108
        syscall
        ret

%endif

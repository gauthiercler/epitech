%ifndef SETFSUID
%define SETFSUID

section .text
    global setfsuid:function

setfsuid:
        mov rax, 122
        syscall
        ret

%endif

%ifndef CHOWN
%define CHOWN

section .text
    global chown:function

chown:
        mov rax, 92
        syscall
        ret

%endif

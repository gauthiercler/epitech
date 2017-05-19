%ifndef SOCKET
%define SOCKET

section .text
    global socket:function

socket:
        mov rax, 41
        syscall
        ret

%endif

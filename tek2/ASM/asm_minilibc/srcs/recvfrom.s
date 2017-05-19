%ifndef RECVFROM
%define RECVFROM

section .text
    global recvfrom:function

recvfrom:
        mov rax, 45
        syscall
        ret

%endif

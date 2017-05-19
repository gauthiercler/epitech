%ifndef RECVMMSG
%define RECVMMSG

section .text
    global recvmmsg:function

recvmmsg:
        mov rax, 299
        syscall
        ret

%endif

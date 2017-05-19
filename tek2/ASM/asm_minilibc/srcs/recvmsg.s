%ifndef RECVMSG
%define RECVMSG

section .text
    global recvmsg:function

recvmsg:
        mov rax, 47
        syscall
        ret

%endif

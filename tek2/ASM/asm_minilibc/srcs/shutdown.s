%ifndef SHUTDOWN
%define SHUTDOWN

section .text
    global shutdown:function

shutdown:
        mov rax, 48
        syscall
        ret

%endif

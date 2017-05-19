%ifndef SIGNALFD
%define SIGNALFD

section .text
    global signalfd:function

signalfd:
        mov rax, 282
        syscall
        ret

%endif

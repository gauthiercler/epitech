%ifndef SIGNALFD4
%define SIGNALFD4

section .text
    global signalfd4:function

signalfd4:
        mov rax, 289
        syscall
        ret

%endif

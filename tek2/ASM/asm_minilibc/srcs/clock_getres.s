%ifndef CLOCK_GETRES
%define CLOCK_GETRES

section .text
    global clock_getres:function

clock_getres:
        mov rax, 229
        syscall
        ret

%endif

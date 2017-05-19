%ifndef ADJTIMEX
%define ADJTIMEX

section .text
    global adjtimex:function

adjtimex:
        mov rax, 159
        syscall
        ret

%endif

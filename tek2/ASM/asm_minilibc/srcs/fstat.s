%ifndef FSTAT
%define FSTAT

section .text
    global fstat:function

fstat:
        mov rax, 5
        syscall
        ret

%endif

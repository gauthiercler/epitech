%ifndef USTAT
%define USTAT

section .text
    global ustat:function

ustat:
        mov rax, 136
        syscall
        ret

%endif

%ifndef SPLICE
%define SPLICE

section .text
    global splice:function

splice:
        mov rax, 275
        syscall
        ret

%endif

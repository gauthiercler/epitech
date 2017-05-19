%ifndef MPROTECT
%define MPROTECT

section .text
    global mprotect:function

mprotect:
        mov rax, 10
        syscall
        ret

%endif

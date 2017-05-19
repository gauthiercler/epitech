%ifndef GETRLIMIT
%define GETRLIMIT

section .text
    global getrlimit:function

getrlimit:
        mov rax, 97
        syscall
        ret

%endif

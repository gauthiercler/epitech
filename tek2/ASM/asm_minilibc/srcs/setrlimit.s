%ifndef SETRLIMIT
%define SETRLIMIT

section .text
    global setrlimit:function

setrlimit:
        mov rax, 160
        syscall
        ret

%endif

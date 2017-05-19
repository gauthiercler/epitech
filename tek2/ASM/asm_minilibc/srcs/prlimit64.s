%ifndef PRLIMIT64
%define PRLIMIT64

section .text
    global prlimit64:function

prlimit64:
        mov rax, 302
        syscall
        ret

%endif

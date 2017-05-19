%ifndef PWRITE64
%define PWRITE64

section .text
    global pwrite64:function

pwrite64:
        mov rax, 18
        syscall
        ret

%endif

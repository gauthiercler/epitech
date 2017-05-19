%ifndef PREAD64
%define PREAD64

section .text
    global pread64:function

pread64:
        mov rax, 17
        syscall
        ret

%endif

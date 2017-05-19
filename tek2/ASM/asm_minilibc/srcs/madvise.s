%ifndef MADVISE
%define MADVISE

section .text
    global madvise:function

madvise:
        mov rax, 28
        syscall
        ret

%endif

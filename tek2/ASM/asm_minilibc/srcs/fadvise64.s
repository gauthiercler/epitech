%ifndef FADVISE64
%define FADVISE64

section .text
    global fadvise64:function

fadvise64:
        mov rax, 221
        syscall
        ret

%endif

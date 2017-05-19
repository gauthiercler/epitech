%ifndef MMAP
%define MMAP

section .text
    global mmap:function

mmap:
        mov rax, 9
        syscall
        ret

%endif

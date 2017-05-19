%ifndef MUNMAP
%define MUNMAP

section .text
    global munmap:function

munmap:
        mov rax, 11
        syscall
        ret

%endif

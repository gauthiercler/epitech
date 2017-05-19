%ifndef SYMLINK
%define SYMLINK

section .text
    global symlink:function

symlink:
        mov rax, 88
        syscall
        ret

%endif

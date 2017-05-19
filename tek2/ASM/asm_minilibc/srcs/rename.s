%ifndef RENAME
%define RENAME

section .text
    global rename:function

rename:
        mov rax, 82
        syscall
        ret

%endif

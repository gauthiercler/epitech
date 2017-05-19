%ifndef FSTATFS
%define FSTATFS

section .text
    global fstatfs:function

fstatfs:
        mov rax, 138
        syscall
        ret

%endif

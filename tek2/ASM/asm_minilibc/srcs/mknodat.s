%ifndef MKNODAT
%define MKNODAT

section .text
    global mknodat:function

mknodat:
        mov rax, 259
        syscall
        ret

%endif

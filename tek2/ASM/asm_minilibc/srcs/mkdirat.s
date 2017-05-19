%ifndef MKDIRAT
%define MKDIRAT

section .text
    global mkdirat:function

mkdirat:
        mov rax, 258
        syscall
        ret

%endif

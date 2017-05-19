%ifndef TRUNCATE
%define TRUNCATE

section .text
    global truncate:function

truncate:
        mov rax, 76
        syscall
        ret

%endif

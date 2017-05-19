%ifndef UTIMES
%define UTIMES

section .text
    global utimes:function

utimes:
        mov rax, 235
        syscall
        ret

%endif

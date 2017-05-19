%ifndef ACCEPT
%define ACCEPT

section .text
    global accept:function

accept:
        mov rax, 43
        syscall
        ret

%endif

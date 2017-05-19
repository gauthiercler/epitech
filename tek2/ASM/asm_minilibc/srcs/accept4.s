%ifndef ACCEPT4
%define ACCEPT4

section .text
    global accept4:function

accept4:
        mov rax, 288
        syscall
        ret

%endif

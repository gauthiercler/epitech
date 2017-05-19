%ifndef CHMOD
%define CHMOD

section .text
    global chmod:function

chmod:
        mov rax, 90
        syscall
        ret

%endif

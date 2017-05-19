%ifndef BRK
%define BRK

section .text
    global brk:function

brk:
        mov rax, 12
        syscall
        ret

%endif

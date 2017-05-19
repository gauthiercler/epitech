%ifndef WRITE
%define WRITE

section .text
    global write:function

write:
        mov rax, 1
        syscall
        ret

%endif

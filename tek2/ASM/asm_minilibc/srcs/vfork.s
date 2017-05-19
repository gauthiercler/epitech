%ifndef VFORK
%define VFORK

section .text
    global vfork:function

vfork:
        mov rax, 58
        syscall
        ret

%endif

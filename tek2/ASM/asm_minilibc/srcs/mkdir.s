%ifndef MKDIR
%define MKDIR

section .text
    global mkdir:function

mkdir:
        mov rax, 83
        syscall
        ret

%endif

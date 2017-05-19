%ifndef RENAMEAT
%define RENAMEAT

section .text
    global renameat:function

renameat:
        mov rax, 264
        syscall
        ret

%endif

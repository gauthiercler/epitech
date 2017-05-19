%ifndef RENAMEAT2
%define RENAMEAT2

section .text
    global renameat2:function

renameat2:
        mov rax, 316
        syscall
        ret

%endif

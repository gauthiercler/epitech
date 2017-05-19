%ifndef PAUSE
%define PAUSE

section .text
    global pause:function

pause:
        mov rax, 34
        syscall
        ret

%endif

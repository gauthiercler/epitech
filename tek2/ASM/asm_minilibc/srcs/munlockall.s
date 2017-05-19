%ifndef MUNLOCKALL
%define MUNLOCKALL

section .text
    global munlockall:function

munlockall:
        mov rax, 152
        syscall
        ret

%endif

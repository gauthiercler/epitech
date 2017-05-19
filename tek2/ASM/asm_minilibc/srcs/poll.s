%ifndef POLL
%define POLL

section .text
    global poll:function

poll:
        mov rax, 7
        syscall
        ret

%endif

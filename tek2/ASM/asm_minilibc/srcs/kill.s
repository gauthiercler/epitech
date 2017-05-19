%ifndef KILL
%define KILL

section .text
    global kill:function

kill:
        mov rax, 62
        syscall
        ret

%endif

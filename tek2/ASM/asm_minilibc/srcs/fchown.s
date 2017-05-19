%ifndef FCHOWN
%define FCHOWN

section .text
    global fchown:function

fchown:
        mov rax, 93
        syscall
        ret

%endif

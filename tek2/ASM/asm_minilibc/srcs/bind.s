%ifndef BIND
%define BIND

section .text
    global bind:function

bind:
        mov rax, 49
        syscall
        ret

%endif

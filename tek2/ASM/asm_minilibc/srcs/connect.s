%ifndef CONNECT
%define CONNECT

section .text
    global connect:function

connect:
        mov rax, 42
        syscall
        ret

%endif

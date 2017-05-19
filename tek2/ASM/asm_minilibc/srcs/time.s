%ifndef TIME
%define TIME

section .text
    global time:function

time:
        mov rax, 201
        syscall
        ret

%endif

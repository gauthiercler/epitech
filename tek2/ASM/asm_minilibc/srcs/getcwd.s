%ifndef GETCWD
%define GETCWD

section .text
    global getcwd:function

getcwd:
        mov rax, 79
        syscall
        ret

%endif

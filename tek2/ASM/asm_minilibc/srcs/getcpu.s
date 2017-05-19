%ifndef GETCPU
%define GETCPU

section .text
    global getcpu:function

getcpu:
        mov rax, 309
        syscall
        ret

%endif

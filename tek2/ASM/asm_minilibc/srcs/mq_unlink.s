%ifndef MQ_UNLINK
%define MQ_UNLINK

section .text
    global mq_unlink:function

mq_unlink:
        mov rax, 241
        syscall
        ret

%endif

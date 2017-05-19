%ifndef MQ_GETSETATTR
%define MQ_GETSETATTR

section .text
    global mq_getsetattr:function

mq_getsetattr:
        mov rax, 245
        syscall
        ret

%endif

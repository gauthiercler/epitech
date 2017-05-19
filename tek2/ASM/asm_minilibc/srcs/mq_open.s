%ifndef MQ_OPEN
%define MQ_OPEN

section .text
    global mq_open:function

mq_open:
        mov rax, 240
        syscall
        ret

%endif

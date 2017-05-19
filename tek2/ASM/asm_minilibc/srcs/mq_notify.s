%ifndef MQ_NOTIFY
%define MQ_NOTIFY

section .text
    global mq_notify:function

mq_notify:
        mov rax, 244
        syscall
        ret

%endif

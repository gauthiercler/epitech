%ifndef MQ_TIMEDRECEIVE
%define MQ_TIMEDRECEIVE

section .text
    global mq_timedreceive:function

mq_timedreceive:
        mov rax, 243
        syscall
        ret

%endif

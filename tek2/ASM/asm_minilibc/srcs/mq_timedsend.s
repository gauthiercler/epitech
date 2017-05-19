%ifndef MQ_TIMEDSEND
%define MQ_TIMEDSEND

section .text
    global mq_timedsend:function

mq_timedsend:
        mov rax, 242
        syscall
        ret

%endif

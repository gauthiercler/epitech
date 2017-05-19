%ifndef PUTPMSG
%define PUTPMSG

section .text
    global putpmsg:function

putpmsg:
        mov rax, 182
        syscall
        ret

%endif

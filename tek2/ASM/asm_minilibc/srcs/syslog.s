%ifndef SYSLOG
%define SYSLOG

section .text
    global syslog:function

syslog:
        mov rax, 103
        syscall
        ret

%endif

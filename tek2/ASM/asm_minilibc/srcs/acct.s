%ifndef ACCT
%define ACCT

section .text
    global acct:function

acct:
        mov rax, 163
        syscall
        ret

%endif

%ifndef UNSHARE
%define UNSHARE

section .text
    global unshare:function

unshare:
        mov rax, 272
        syscall
        ret

%endif

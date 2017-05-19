%ifndef PPOLL
%define PPOLL

section .text
    global ppoll:function

ppoll:
        mov rax, 271
        syscall
        ret

%endif

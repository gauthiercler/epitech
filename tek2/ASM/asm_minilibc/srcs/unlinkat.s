%ifndef UNLINKAT
%define UNLINKAT

section .text
    global unlinkat:function

unlinkat:
        mov rax, 263
        syscall
        ret

%endif

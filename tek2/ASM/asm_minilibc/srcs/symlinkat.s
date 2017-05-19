%ifndef SYMLINKAT
%define SYMLINKAT

section .text
    global symlinkat:function

symlinkat:
        mov rax, 266
        syscall
        ret

%endif

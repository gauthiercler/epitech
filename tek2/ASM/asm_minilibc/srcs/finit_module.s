%ifndef FINIT_MODULE
%define FINIT_MODULE

section .text
    global finit_module:function

finit_module:
        mov rax, 313
        syscall
        ret

%endif

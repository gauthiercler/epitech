%ifndef INIT_MODULE
%define INIT_MODULE

section .text
    global init_module:function

init_module:
        mov rax, 175
        syscall
        ret

%endif

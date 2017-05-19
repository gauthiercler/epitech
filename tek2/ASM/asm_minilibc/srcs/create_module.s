%ifndef CREATE_MODULE
%define CREATE_MODULE

section .text
    global create_module:function

create_module:
        mov rax, 174
        syscall
        ret

%endif

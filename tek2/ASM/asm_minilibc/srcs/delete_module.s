%ifndef DELETE_MODULE
%define DELETE_MODULE

section .text
    global delete_module:function

delete_module:
        mov rax, 176
        syscall
        ret

%endif

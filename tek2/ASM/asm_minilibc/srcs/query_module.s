%ifndef QUERY_MODULE
%define QUERY_MODULE

section .text
    global query_module:function

query_module:
        mov rax, 178
        syscall
        ret

%endif

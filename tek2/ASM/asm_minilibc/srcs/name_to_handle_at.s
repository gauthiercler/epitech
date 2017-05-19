%ifndef NAME_TO_HANDLE_AT
%define NAME_TO_HANDLE_AT

section .text
    global name_to_handle_at:function

name_to_handle_at:
        mov rax, 303
        syscall
        ret

%endif

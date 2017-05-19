%ifndef OPEN_BY_HANDLE_AT
%define OPEN_BY_HANDLE_AT

section .text
    global open_by_handle_at:function

open_by_handle_at:
        mov rax, 304
        syscall
        ret

%endif

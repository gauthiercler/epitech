%ifndef SET_TID_ADDRESS
%define SET_TID_ADDRESS

section .text
    global set_tid_address:function

set_tid_address:
        mov rax, 218
        syscall
        ret

%endif

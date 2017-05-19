%ifndef SET_ROBUST_LIST
%define SET_ROBUST_LIST

section .text
    global set_robust_list:function

set_robust_list:
        mov rax, 273
        syscall
        ret

%endif

%ifndef GET_ROBUST_LIST
%define GET_ROBUST_LIST

section .text
    global get_robust_list:function

get_robust_list:
        mov rax, 274
        syscall
        ret

%endif

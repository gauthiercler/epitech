%ifndef SELECT
%define SELECT

section .text
    global select:function

select:
        mov rax, 23
        syscall
        ret

%endif

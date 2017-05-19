%ifndef PIVOT_ROOT
%define PIVOT_ROOT

section .text
    global pivot_root:function

pivot_root:
        mov rax, 155
        syscall
        ret

%endif

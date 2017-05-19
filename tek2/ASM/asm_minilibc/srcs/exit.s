%ifndef EXIT
%define EXIT

section .text
    global exit:function

exit:
        mov rax, 60
        syscall
        ret

%endif

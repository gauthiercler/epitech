%ifndef EXIT_GROUP
%define EXIT_GROUP

section .text
    global exit_group:function

exit_group:
        mov rax, 231
        syscall
        ret

%endif

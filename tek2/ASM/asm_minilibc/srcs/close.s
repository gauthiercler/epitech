%ifndef CLOSE
%define CLOSE

section .text
    global close:function

close:
        mov rax, 3
        syscall
        ret

%endif

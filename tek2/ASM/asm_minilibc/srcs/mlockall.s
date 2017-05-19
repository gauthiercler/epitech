%ifndef MLOCKALL
%define MLOCKALL

section .text
    global mlockall:function

mlockall:
        mov rax, 151
        syscall
        ret

%endif

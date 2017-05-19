%ifndef READAHEAD
%define READAHEAD

section .text
    global readahead:function

readahead:
        mov rax, 187
        syscall
        ret

%endif

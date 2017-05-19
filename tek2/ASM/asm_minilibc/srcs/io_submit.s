%ifndef IO_SUBMIT
%define IO_SUBMIT

section .text
    global io_submit:function

io_submit:
        mov rax, 209
        syscall
        ret

%endif

%ifndef IO_DESTROY
%define IO_DESTROY

section .text
    global io_destroy:function

io_destroy:
        mov rax, 207
        syscall
        ret

%endif

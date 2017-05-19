%ifndef ADD_KEY
%define ADD_KEY

section .text
    global add_key:function

add_key:
        mov rax, 248
        syscall
        ret

%endif

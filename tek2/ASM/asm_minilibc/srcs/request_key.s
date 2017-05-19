%ifndef REQUEST_KEY
%define REQUEST_KEY

section .text
    global request_key:function

request_key:
        mov rax, 249
        syscall
        ret

%endif

%ifndef GET_THREAD_AREA
%define GET_THREAD_AREA

section .text
    global get_thread_area:function

get_thread_area:
        mov rax, 211
        syscall
        ret

%endif

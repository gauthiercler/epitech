%ifndef SET_THREAD_AREA
%define SET_THREAD_AREA

section .text
    global set_thread_area:function

set_thread_area:
        mov rax, 205
        syscall
        ret

%endif

%ifndef FANOTIFY_INIT
%define FANOTIFY_INIT

section .text
    global fanotify_init:function

fanotify_init:
        mov rax, 300
        syscall
        ret

%endif

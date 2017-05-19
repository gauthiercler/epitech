%ifndef MOVE_PAGES
%define MOVE_PAGES

section .text
    global move_pages:function

move_pages:
        mov rax, 279
        syscall
        ret

%endif

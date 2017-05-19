%ifndef MIGRATE_PAGES
%define MIGRATE_PAGES

section .text
    global migrate_pages:function

migrate_pages:
        mov rax, 256
        syscall
        ret

%endif

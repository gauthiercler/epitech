%ifndef AFS_SYSCALL
%define AFS_SYSCALL

section .text
    global afs_syscall:function

afs_syscall:
        mov rax, 183
        syscall
        ret

%endif

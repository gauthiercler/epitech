%ifndef PROCESS_VM_READV
%define PROCESS_VM_READV

section .text
    global process_vm_readv:function

process_vm_readv:
        mov rax, 310
        syscall
        ret

%endif

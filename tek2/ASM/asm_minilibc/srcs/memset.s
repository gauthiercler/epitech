%ifndef MEMSET
%define MEMSET

section .text
    global memset:function


memset:
	mov rax, rdi

memset_compute:
	cmp rdx, 0
	je memset_end
	mov [rdi], sil
	dec rdx
	inc rdi
	jmp memset_compute

memset_end:
	ret

%endif
%ifndef STRCHR
%define STRCHR

section .text
    global strchr:function


strchr:	
	xor rax, rax

strchr_compute:
	cmp [rdi], sil
	je set_ptr
	cmp [rdi], byte 0
	je strchr_end
	inc rdi
	jmp strchr_compute

set_ptr:
	mov rax, rdi
strchr_end:
	ret

%endif
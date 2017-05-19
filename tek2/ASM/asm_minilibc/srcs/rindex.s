%ifndef RINDEX
%define RINDEX

section .text
    global rindex:function


rindex:
	xor	rax, rax

rindex_compute:
	cmp [rdi], sil
	je set_ptr
	cmp [rdi], byte 0
	je rindex_end
	inc rdi
	jmp rindex_compute

set_ptr:
	mov rax, rdi
	cmp[rdi], byte 0
	je rindex_end
	inc rdi
	jmp rindex_compute

rindex_end:

	ret

%endif
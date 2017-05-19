%ifndef STRCSPN
%define STRCSPN

section 		.text

	global 		strcspn:function

strcspn:

	mov 		r8, rdi
	xor 		rax, rax

strcspn_core:

	cmp 		[r8], byte 0
	je 			strcspn_end

	mov 		r9, rsi
	string_loop:

		cmp 		[r9], byte 0
		je 			string_loop_end

		mov 		r10b, [r9]
		cmp 		[r8], r10b
		je 			strcspn_end

		inc 		r9
		jmp 		string_loop

	string_loop_end:

	inc 		r8
	inc 		rax
	jmp 		strcspn_core

strcspn_end:

	ret

%endif
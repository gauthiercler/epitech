%ifndef STRSPN
%define STRSPN

section 		.text

	global 		strspn:function

strspn:

	mov 		r8, rdi
	xor 		rax, rax

strspn_core:

	cmp 		[r8], byte 0
	je 			strspn_end

	mov 		r9, rsi
	string_loop:

		cmp 		[r9], byte 0
		je 			string_loop_end

		mov 		r10b, [r9]
		cmp 		[r8], r10b
		jne 		strspn_end

		inc 		r9
		jmp 		string_loop

	string_loop_end:

	inc 		r8
	inc 		rax
	jmp 		strspn_core

strspn_end:

	ret

%endif
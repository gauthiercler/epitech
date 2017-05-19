%ifndef STRNCMP
%define STRNCMP

section 		.text

	global 		strncmp:function

strncmp:

;	push 		rbx 					;Optional
;	push 		r12						;Saving the callee-save registers
;	push 		r13
	xor 		rax, rax				;Sets rax to 0
	xor 		r8, r8

loopOnFirstString:

	cmp 		rdx, 0
	je 			return

	mov 		cl, [rsi + r8]			;Cmp only accepts one memory operand, so we store the byte pointed at by rsi (second argument) in the first 8bytes (least significant) of rcx
	cmp 		[rdi + r8], cl
	jne 		returnDiff 				;If the two characters are different, we return the difference

	cmp 		[rdi + r8], byte 0		;If the first string is over, we stop and return.
	je 			return 					;It is done after the byte comparison in order to handle the '\0' in case the two strings are of different length

	cmp 		[rsi + r8], byte 0		;Same thing for the second string.
	je 			return

	inc 		r8 						;We increment the common string index to get the next character in memory
	dec 		rdx						;We decrement the number of max bytes we can compare
	jmp 		loopOnFirstString

returnDiff:

	movzx 		rax, byte [rdi + r8]	;We move the first sting's byte pointed to by rdi into rax by zero-extending it to 64bits
	movzx 		rcx, byte [rsi + r8]	;Same thing with the second one
	sub 		rax, rcx 				;We sub the second character to the first in RAX

	jmp 		return

return :

;	pop			r13						;Optional
;	pop			r12						;Getting back the callee-save registers
;	pop			rbx
	ret

%endif
%ifndef STRCMP
%define STRCMP

section 		.text

	global 		strcmp:function

strcmp:

;	push 		rbx 					;Optional
;	push 		r12						;Saving the callee-save registers
;	push 		r13
	xor 		rax, rax				;Sets rax to 0
	xor 		rdx, rdx

loopOnFirstString:

	mov 		cl, [rsi + rdx]			;Cmp only accepts one memory operand, so we store the byte pointed at by rsi (second argument) in the first 8bytes (least significant) of rcx
	cmp 		[rdi + rdx], cl
	jne 		returnDiff 				;If the two characters are different, we return the difference

	cmp 		[rdi + rdx], byte 0		;If the first string is over, we stop and return.
	je 			return 					;It is done after the byte comparison in order to handle the '\0' in case the two strings are of different length

	inc 		rdx 					;We increment the common string index to get the next character in memory
	jmp 		loopOnFirstString

returnDiff:

	movzx 		rax, byte [rdi + rdx]	;We move the first sting's byte pointed to by rdi into rax by zero-extending it to 64bits
	movzx 		rcx, byte [rsi + rdx]	;Same thing with the second one
	sub 		rax, rcx 				;We sub the second character to the first in RAX
	
	jmp 		return

return :

;	pop			r13						;Optional
;	pop			r12						;Getting back the callee-save registers
;	pop			rbx
	ret

%endif
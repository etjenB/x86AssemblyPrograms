.386
.model flat,c
.code

CalcArraySumASM proc
	push ebp
	mov ebp,esp

	mov edx,[ebp+8]		;*x
	mov ecx,[ebp+12]	;n
	xor eax,eax

	cmp ecx,0
	jle InvalidCount

@@:
	add eax,[edx]
	add edx,4			;set pointer to next element
	dec ecx
	jnz @B				;jump backwards to the next @@

InvalidCount:
	pop ebp
	ret
CalcArraySumASM endp
end
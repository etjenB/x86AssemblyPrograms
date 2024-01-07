.386
.model flat,c
.code

AdderASM proc
	push ebp			;push ebp register to stack
	mov ebp,esp

	mov eax,[ebp+8]		;setting eax to point at value of ebp + 8 places - there is first parameter value stored (a) 
	mov ecx,[ebp+12]	;setting ecx to point at value of ebp + 12 places - there is second parameter value stored (b) 
	mov edx,[ebp+16]	;setting edx to point at value of ebp + 16 places - there is third parameter value stored (c) 

	add eax,ecx			;adding value from ecx to value in eax register, so a += b
	add eax,edx			;adding value from edx to value in eax register, so a += c

	pop ebp				;pop ebp register from the stack
						;value stored in eax is value that will be looked for as a returning value from function
	ret
AdderASM endp
end
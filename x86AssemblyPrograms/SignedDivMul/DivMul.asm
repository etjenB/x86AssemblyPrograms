.386
.model flat,c

;return : 0 -> error (division by zero)
;		: 1 success
;
;Computation *prod = a*b
;			 *quo = a/b
;			 *rem = a%b

.code
IntegerMulDiv proc
	push ebp			;creating stack
	mov ebp,esp
	push ebx

	xor eax,eax			

	mov ecx,[ebp+8]			;moving first parameter to ecx register
	mov edx,[ebp+12]		;moving second parameter to edx register

	or edx,edx				;if value in edx is 0 then jump to InvalidDivisor logic because division by 0 is not possible
	jz InvalidDivisor

	imul edx,ecx			;multiply value from ecx with value in edx and store result in edx -> edx *= ecx

	mov ebx,[ebp+16]		;move value from third parameter to ebx register
	mov [ebx],edx			;move value from edx to the location where ebx is pointing

	mov eax,ecx				;move value from ecx register(first parameter value) to eax register
	cdq						;edx:eax contains dividend

	idiv dword ptr[ebp+12]  ;division

	mov ebx,[ebp+20]
	mov [ebx],eax
	mov ebx,[ebp+24]
	mov [ebx],edx

	mov eax,1				;eax is the register where return value is checked

	InvalidDivisor:
		pop ebx				;pop ebx from stack
		pop ebp				;pop ebp from stack
		ret

IntegerMulDiv endp
end
.686
.model flat,c

.code
SignedMinA proc
	push ebp
	mov ebp,esp

	mov eax,[ebp+8]
	mov ecx,[ebp+12]

	cmp eax,ecx
	jle @F
	mov eax,ecx

@@:
	mov ecx,[ebp+16]
	cmp eax,ecx
	jle @F
	mov eax,ecx

@@:
	pop ebp
	ret
SignedMinA endp

SignedMaxA proc
	push ebp
	mov ebp,esp

	mov eax,[ebp+8]
	mov ecx,[ebp+12]

	cmp eax,ecx
	jge @F
	mov eax,ecx

@@:
	mov ecx,[ebp+16]
	cmp eax,ecx
	jge @F
	mov eax,ecx

@@:
	pop ebp
	ret
SignedMaxA endp

SignedMinB proc
	push ebp
	mov ebp,esp

	mov eax,[ebp+8]
	mov ecx,[ebp+12]

	cmp eax,ecx
	cmovg eax,ecx			;cmovl will compare the values in two given registers eax and ecx and put in first register(eax) the smaller value
							;this will work for signed integers, but for unsigned integers cmova can be used for same purpose

	mov ecx,[ebp+16]

	cmp eax,ecx
	cmovg eax,ecx

	pop ebp

	ret
SignedMinB endp

SignedMaxB proc
	push ebp
	mov ebp,esp

	mov eax,[ebp+8]
	mov ecx,[ebp+12]

	cmp eax,ecx
	cmovl eax,ecx			;cmovl will compare the values in two given registers eax and ecx and put in first register(eax) the greater value
							;this will work for signed integers, but for unsigned integers cmovb can be used for same purpose

	mov ecx,[ebp+16]

	cmp eax,ecx
	cmovl eax,ecx

	pop ebp

	ret
SignedMaxB endp
end
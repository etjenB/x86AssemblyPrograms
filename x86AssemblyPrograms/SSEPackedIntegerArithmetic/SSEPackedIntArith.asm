.model flat,c

.code
SsePackedInt16_Add proc
	push ebp
	mov ebp,esp

	mov eax,[ebp+8]
	mov ecx,[ebp+12]
	mov edx,[ebp+16]

	movdqa xmm0,[eax]
	movdqa xmm1,xmm0
	movdqa xmm2,[ecx]

	paddw xmm0,xmm2
	paddw xmm1,xmm2

	movdqa [edx],xmm0
	movdqa [edx+16],xmm1

	pop ebp
	ret
SsePackedInt16_Add endp

SsePackedInt32_Sub proc
	push ebp
	mov ebp,esp

	mov eax,[ebp+8]
	mov ecx,[ebp+12]
	mov edx,[ebp+16]

	movdqa xmm0,[eax]
	psubd xmm0,[ecx]

	movdqu [edx],xmm0

	pop ebp
	ret
SsePackedInt32_Sub endp

SsePackedInt32_Mul proc
	push ebp
	mov ebp,esp

	mov eax,[ebp+8]
	mov ecx,[ebp+12]
	mov edx,[ebp+16]

	movdqa xmm0,[eax]
	movdqa xmm1,[ecx]

	movdqa xmm2,xmm0
	pmulld xmm0,xmm1
	pmuldq xmm2,xmm1

	movdqa [edx],xmm0
	movdqa [edx+16],xmm2

	pop ebp
	ret
SsePackedInt32_Mul endp
end
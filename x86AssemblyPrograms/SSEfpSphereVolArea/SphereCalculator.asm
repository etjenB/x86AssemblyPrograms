.model flat,c

.const
	r8_pi real8 3.14159265358979323846
	r8_four real8 4.0
	r8_three real8 3.0
	r8_neg_one real8 -1.0

.code
SseSphereCalculator proc

	push ebp
	mov ebp,esp

	movsd xmm0,real8 ptr[ebp+8]				;xmm0=r
	mov ecx,[ebp+16]						;ecx=sa
	mov edx,[ebp+20]						;edx=v

	xorpd xmm7,xmm7							;xmm7=0.0
	comisd xmm0,xmm7						;compare r with xmm7(0.0)
	jp BadRadius							;if value in xmm0 is undefined go to BadRadius
	jb BadRadius							;if value in xmm0 is less then value in xmm7(0.0) go to BadRadius

;Surface area -> 4*Pi*r^2
	movsd xmm1,xmm0
	mulsd xmm1,xmm1
	mulsd xmm1,[r8_four]
	mulsd xmm1,[r8_pi]
	movsd real8 ptr[ecx],xmm1				;save surface area

;Volume -> 4*Pi*r^3
	mulsd xmm1,xmm0
	divsd xmm1,[r8_three]
	movsd real8 ptr[edx],xmm1
	mov eax,1
	pop ebp
	ret

BadRadius:
	movsd xmm0,[r8_neg_one]
	movsd real8 ptr[ecx],xmm0
	movsd real8 ptr[edx],xmm0
	xor eax,eax
	pop ebp
	ret
SseSphereCalculator endp
end
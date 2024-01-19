.model flat,c

.const
AbsMask qword 7fffffffffffffffh, 7fffffffffffffffh

.code
AVX_fp_Arith proc
	push ebp
	mov ebp,esp

	mov eax,[ebp+24]
	vmovsd xmm0,real8 ptr[ebp+8]
	vmovsd xmm1,real8 ptr[ebp+16]

	vaddsd xmm2,xmm0,xmm1

	vsubsd xmm3,xmm0,xmm1

	vmulsd xmm4,xmm0,xmm1

	vdivsd xmm5,xmm0,xmm1

	vmovsd real8 ptr[eax],xmm2
	vmovsd real8 ptr[eax+8],xmm3
	vmovsd real8 ptr[eax+16],xmm4
	vmovsd real8 ptr[eax+24],xmm5

	vminsd xmm2,xmm0,xmm1
	
	vmaxsd xmm3,xmm0,xmm1

	vsqrtsd xmm4,xmm0,xmm0

	vandpd xmm5,xmm1,xmmword ptr[AbsMask]

	vmovsd real8 ptr[eax+32],xmm2
	vmovsd real8 ptr[eax+40],xmm3
	vmovsd real8 ptr[eax+48],xmm4
	vmovsd real8 ptr[eax+56],xmm5

	pop ebp
	ret
AVX_fp_Arith endp
end
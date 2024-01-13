;F to C : Deduct 32, then multiply by 5, then divide by 9
;C to F : Multiply by 9, then divide by 5 and then add 32

.model flat,c

.const
r8_SfFtoC real8 0.5555555556			;5/9
r8_SfCtoF real8 1.8						;9/5
i4_32 dword 32

.code
FtoC proc
	push ebp
	mov ebp,esp

	fld [r8_SfFtoC]						;floating point load, load r8_SfFtoC to FPU stack, the stack is filo(first in last out)
	fld real8 ptr[ebp+8]				;load first parameter to FPU stack
	fild[i4_32]							;floating point integer load

	fsubp								;ST(1) = ST(1) - ST(0) -> pop current ST(0), so ST(1) becomes ST(0) // f - 32
	fmulp								;ST(1) = ST(1) * ST(0) -> pop current ST(0), so ST(1) becomes ST(0) // (f-32) * 5/9

	ret
FtoC endp
end
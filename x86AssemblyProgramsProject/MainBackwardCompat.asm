
;.code
;MainBackwardCompat proc
;	mov rax,2
;	mov rbx,3
;	mov rcx,4
;	ret
;MainBackwardCompat endp
;end

;.386
;.model flat
;.code
;MainBackwardCompat proc
;	mov eax,2
;	mov ebx,3
;	mov ecx,4
;	ret
;MainBackwardCompat endp
;end MainBackwardCompat

.386
.model flat
.code
MainBackwardCompat proc
	mov ax,2
	mov bx,3
	mov cx,4
	ret
MainBackwardCompat endp
end MainBackwardCompat
BITS 64
default rel

				section		.text
				global		_ft_strlen


_pd_beg:		test		rax, 0111b				; Padding our address in RAX to 8
				jz			_main_loop
				cmp			byte [rax], 0h			; if char is not null, continue padding
				je			_finish
				add			rax, 1
				jmp			_pd_beg


_main_loop:		mov			rcx, 0101010101010101h  ; Magix number 1
				mov			rsi, 8080808080808080h  ; Magix number 2
				mov			r8, 8h					; Size of longword


_m_bg_loop:		mov			rdx, [rax]              ; inverted
				mov			rbx, rdx                ; substituted

				sub			rbx, rcx                ; Substitution of a magix
				and			rbx, rsi                ; Making magical AND
				not			rdx
				and			rbx, rdx
				not			rbx                     ; if not zero
				jnz			_inject_byte            ; FIND A ZERO_BYTE
				add			rax, r8
				jmp			_m_bg_loop


_inject_byte:	cmp			byte [rax], 0h
				je			_finish
				add			rax, 1
				jmp			_inject_byte


_ft_strlen:		push		rbp
				mov			rbp, rsp
				push		rbx

				mov			rax, rdi
				jmp			_pd_beg


_finish:		mov			rbx, rax			; В rax хранится адресс '\0'
				sub			rbx, rdi
				mov			rax, rbx

				pop			rbx
				mov			rsp, rbp
				pop			rbp
				ret

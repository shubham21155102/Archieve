	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 14, 0	sdk_version 14, 2
	.globl	_check                          ; -- Begin function check
	.p2align	2
_check:                                 ; @check
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	.cfi_def_cfa_offset 32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x0, [sp, #8]
	bl	_pthread_self
	str	x0, [sp]
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	mov	w0, #1
	bl	_sleep
	adrp	x0, l_.str.1@PAGE
	add	x0, x0, l_.str.1@PAGEOFF
	bl	_printf
	mov	x0, #0
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	.cfi_def_cfa_offset 48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	sub	x0, x29, #8
	mov	x3, #0
	str	x3, [sp, #8]                    ; 8-byte Folded Spill
	mov	x1, x3
	adrp	x2, _check@PAGE
	add	x2, x2, _check@PAGEOFF
	str	x2, [sp]                        ; 8-byte Folded Spill
	bl	_pthread_create
	ldr	x2, [sp]                        ; 8-byte Folded Reload
	ldr	x3, [sp, #8]                    ; 8-byte Folded Reload
	add	x0, sp, #16
	mov	x1, x3
	bl	_pthread_create
	ldr	x1, [sp, #8]                    ; 8-byte Folded Reload
	ldur	x0, [x29, #-8]
	bl	_pthread_join
	ldr	x1, [sp, #8]                    ; 8-byte Folded Reload
	ldr	x0, [sp, #16]
	bl	_pthread_join
	mov	w0, #0
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"Hello World from Thread\n"

l_.str.1:                               ; @.str.1
	.asciz	"Checking Parallel Execution from Thread\n"

.subsections_via_symbols

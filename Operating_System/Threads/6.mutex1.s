	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 14, 0	sdk_version 14, 2
	.globl	_resume                         ; -- Begin function resume
	.p2align	2
_resume:                                ; @resume
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	.cfi_def_cfa_offset 48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	stur	wzr, [x29, #-12]
	b	LBB0_1
LBB0_1:                                 ; =>This Inner Loop Header: Depth=1
	ldur	w8, [x29, #-12]
	mov	w9, #16960
	movk	w9, #15, lsl #16
	subs	w8, w8, w9
	cset	w8, ge
	tbnz	w8, #0, LBB0_4
	b	LBB0_2
LBB0_2:                                 ;   in Loop: Header=BB0_1 Depth=1
	adrp	x0, _lock@GOTPAGE
	ldr	x0, [x0, _lock@GOTPAGEOFF]
	str	x0, [sp, #8]                    ; 8-byte Folded Spill
	bl	_pthread_mutex_lock
	ldr	x0, [sp, #8]                    ; 8-byte Folded Reload
	adrp	x9, _mails@PAGE
	ldr	w8, [x9, _mails@PAGEOFF]
	add	w8, w8, #1
	str	w8, [x9, _mails@PAGEOFF]
	bl	_pthread_mutex_unlock
	b	LBB0_3
LBB0_3:                                 ;   in Loop: Header=BB0_1 Depth=1
	ldur	w8, [x29, #-12]
	add	w8, w8, #1
	stur	w8, [x29, #-12]
	b	LBB0_1
LBB0_4:
	mov	x0, #0
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #80
	.cfi_def_cfa_offset 80
	stp	x29, x30, [sp, #64]             ; 16-byte Folded Spill
	add	x29, sp, #64
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	mov	w8, #0
	stur	w8, [x29, #-28]                 ; 4-byte Folded Spill
	stur	wzr, [x29, #-4]
	adrp	x0, _lock@GOTPAGE
	ldr	x0, [x0, _lock@GOTPAGEOFF]
	mov	x1, #0
	str	x1, [sp, #24]                   ; 8-byte Folded Spill
	bl	_pthread_mutex_init
	ldr	x3, [sp, #24]                   ; 8-byte Folded Reload
	sub	x0, x29, #16
	mov	x1, x3
	adrp	x2, _resume@PAGE
	add	x2, x2, _resume@PAGEOFF
	str	x2, [sp, #16]                   ; 8-byte Folded Spill
	bl	_pthread_create
	ldr	x2, [sp, #16]                   ; 8-byte Folded Reload
	ldr	x3, [sp, #24]                   ; 8-byte Folded Reload
	sub	x0, x29, #24
	mov	x1, x3
	bl	_pthread_create
	ldr	x1, [sp, #24]                   ; 8-byte Folded Reload
	ldur	x0, [x29, #-16]
	bl	_pthread_join
	ldr	x1, [sp, #24]                   ; 8-byte Folded Reload
	ldur	x0, [x29, #-24]
	bl	_pthread_join
	adrp	x8, _mails@PAGE
	ldr	w9, [x8, _mails@PAGEOFF]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	ldur	w0, [x29, #-28]                 ; 4-byte Folded Reload
	ldp	x29, x30, [sp, #64]             ; 16-byte Folded Reload
	add	sp, sp, #80
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_mails                          ; @mails
.zerofill __DATA,__common,_mails,4,2
	.comm	_lock,64,3                      ; @lock
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"Number of mails: %d\n"

.subsections_via_symbols

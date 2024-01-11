	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 14, 0	sdk_version 14, 2
	.globl	_routine                        ; -- Begin function routine
	.p2align	2
_routine:                               ; @routine
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	wzr, [sp, #12]
	b	LBB0_1
LBB0_1:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #12]
	subs	w8, w8, #1000
	cset	w8, ge
	tbnz	w8, #0, LBB0_4
	b	LBB0_2
LBB0_2:                                 ;   in Loop: Header=BB0_1 Depth=1
	adrp	x9, _mails@PAGE
	ldr	w8, [x9, _mails@PAGEOFF]
	add	w8, w8, #1
	str	w8, [x9, _mails@PAGEOFF]
	b	LBB0_3
LBB0_3:                                 ;   in Loop: Header=BB0_1 Depth=1
	ldr	w8, [sp, #12]
	add	w8, w8, #1
	str	w8, [sp, #12]
	b	LBB0_1
LBB0_4:
	mov	x0, #0
	add	sp, sp, #16
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
	stur	wzr, [x29, #-4]
	stur	w0, [x29, #-8]
	stur	x1, [x29, #-16]
	sub	x0, x29, #24
	mov	x3, #0
	mov	x1, x3
	adrp	x2, _routine@PAGE
	add	x2, x2, _routine@PAGEOFF
	bl	_pthread_create
	subs	w8, w0, #0
	cset	w8, eq
	tbnz	w8, #0, LBB1_2
	b	LBB1_1
LBB1_1:
	mov	w8, #1
	stur	w8, [x29, #-4]
	b	LBB1_9
LBB1_2:
	add	x0, sp, #32
	mov	x3, #0
	mov	x1, x3
	adrp	x2, _routine@PAGE
	add	x2, x2, _routine@PAGEOFF
	bl	_pthread_create
	subs	w8, w0, #0
	cset	w8, eq
	tbnz	w8, #0, LBB1_4
	b	LBB1_3
LBB1_3:
	mov	w8, #2
	stur	w8, [x29, #-4]
	b	LBB1_9
LBB1_4:
	ldur	x0, [x29, #-24]
	mov	x1, #0
	bl	_pthread_join
	subs	w8, w0, #0
	cset	w8, eq
	tbnz	w8, #0, LBB1_6
	b	LBB1_5
LBB1_5:
	mov	w8, #3
	stur	w8, [x29, #-4]
	b	LBB1_9
LBB1_6:
	ldr	x0, [sp, #32]
	mov	x1, #0
	bl	_pthread_join
	subs	w8, w0, #0
	cset	w8, eq
	tbnz	w8, #0, LBB1_8
	b	LBB1_7
LBB1_7:
	mov	w8, #4
	stur	w8, [x29, #-4]
	b	LBB1_9
LBB1_8:
	adrp	x8, _mails@PAGE
	ldr	w9, [x8, _mails@PAGEOFF]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	stur	wzr, [x29, #-4]
	b	LBB1_9
LBB1_9:
	ldur	w0, [x29, #-4]
	ldp	x29, x30, [sp, #64]             ; 16-byte Folded Reload
	add	sp, sp, #80
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_mails                          ; @mails
.zerofill __DATA,__common,_mails,4,2
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"Number of mails: %d\n"

.subsections_via_symbols

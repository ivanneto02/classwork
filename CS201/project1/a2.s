	.text
	.file	"test.c"
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3, 0x0                          # -- Begin function main
.LCPI0_0:
	.quad	0x4024333333333333              # double 10.1
	.text
	.globl	main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$0, -4(%rbp)
	movl	$10, -8(%rbp)
	movl	$10, %edi
	movsd	.LCPI0_0(%rip), %xmm0           # xmm0 = mem[0],zero
	movl	$97, %esi
	callq	test
	cmpl	$10, -8(%rbp)
	jne	.LBB0_2
# %bb.1:
	imull	$10, -8(%rbp), %eax
	movl	%eax, -12(%rbp)
	jmp	.LBB0_6
.LBB0_2:
	cmpl	$20, -8(%rbp)
	jne	.LBB0_4
# %bb.3:
	imull	$20, -8(%rbp), %eax
	movl	%eax, -12(%rbp)
	jmp	.LBB0_5
.LBB0_4:
	imull	$30, -8(%rbp), %eax
	movl	%eax, -12(%rbp)
.LBB0_5:
	jmp	.LBB0_6
.LBB0_6:
	leaq	.L.str(%rip), %rdi
	movb	$0, %al
	callq	printf@PLT
	xorl	%eax, %eax
	addq	$16, %rsp
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.globl	test                            # -- Begin function test
	.p2align	4, 0x90
	.type	test,@function
test:                                   # @test
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movb	%sil, %al
	movl	%edi, -4(%rbp)
	movsd	%xmm0, -16(%rbp)
	movb	%al, -17(%rbp)
	cvtsi2sdl	-4(%rbp), %xmm0
	mulsd	-16(%rbp), %xmm0
	movsd	%xmm0, -32(%rbp)
	movb	-17(%rbp), %al
	movb	%al, -33(%rbp)
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end1:
	.size	test, .Lfunc_end1-test
	.cfi_endproc
                                        # -- End function
	.type	.L.str,@object                  # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"Hello world\n"
	.size	.L.str, 13

	.ident	"Ubuntu clang version 17.0.6 (++20231208085846+6009708b4367-1~exp1~20231208085949.74)"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym test
	.addrsig_sym printf

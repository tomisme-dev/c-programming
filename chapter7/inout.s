	.file	"inout.c"
	.text
	.section	.rodata
.LC0:
	.string	"output: %s"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$1072, %rsp
	movl	%edi, -1060(%rbp)
	movq	%rsi, -1072(%rbp)
	movq	%fs:40, %rax
	lock xorq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -1048(%rbp)
	jmp	.L2
.L3:
	movl	-1048(%rbp), %eax
	leal	1(%rax), %edx
	movl	%edx, -1048(%rbp)
	movl	-1044(%rbp), %edx
	cltq
	movb	%dl, -1040(%rbp,%rax)
.L2:
	call	getchar@PLT
	movl	%eax, -1044(%rbp)
	cmpl	$-1, -1044(%rbp)
	jne	.L3
	movl	-1048(%rbp), %eax
	cltq
	movb	$0, -1040(%rbp,%rax)
	leaq	-1040(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L5
	call	__stack_chk_fail@PLT
.L5:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits

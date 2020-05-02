t1:
(__TEXT,__text) section
_GetTime:
0000000100000b20	pushq	%rbp
0000000100000b21	movq	%rsp, %rbp
0000000100000b24	subq	$0x20, %rsp
0000000100000b28	xorl	%eax, %eax
0000000100000b2a	movl	%eax, %esi
0000000100000b2c	leaq	-0x10(%rbp), %rdi
0000000100000b30	callq	0x100000e14 ## symbol stub for: _gettimeofday
0000000100000b35	movl	%eax, -0x14(%rbp)
0000000100000b38	cmpl	$0x0, -0x14(%rbp)
0000000100000b3c	sete	%cl
0000000100000b3f	xorb	$-0x1, %cl
0000000100000b42	andb	$0x1, %cl
0000000100000b45	movzbl	%cl, %eax
0000000100000b48	movslq	%eax, %rsi
0000000100000b4b	cmpq	$0x0, %rsi
0000000100000b4f	je	0x100000b74
0000000100000b55	leaq	0x324(%rip), %rdi ## literal pool for: "GetTime"
0000000100000b5c	leaq	0x325(%rip), %rsi ## literal pool for: "./common.h"
0000000100000b63	leaq	0x329(%rip), %rcx ## literal pool for: "rc == 0"
0000000100000b6a	movl	$0xb, %edx
0000000100000b6f	callq	0x100000e0e ## symbol stub for: ___assert_rtn
0000000100000b74	jmp	0x100000b79
0000000100000b79	movsd	0x2ef(%rip), %xmm0
0000000100000b81	movq	-0x10(%rbp), %rax
0000000100000b85	cvtsi2sdq	%rax, %xmm1
0000000100000b8a	movl	-0x8(%rbp), %ecx
0000000100000b8d	cvtsi2sdl	%ecx, %xmm2
0000000100000b91	divsd	%xmm0, %xmm2
0000000100000b95	addsd	%xmm2, %xmm1
0000000100000b99	movaps	%xmm1, %xmm0
0000000100000b9c	addq	$0x20, %rsp
0000000100000ba0	popq	%rbp
0000000100000ba1	retq
0000000100000ba2	nopw	%cs:(%rax,%rax)
0000000100000bac	nopl	(%rax)
_Spin:
0000000100000bb0	pushq	%rbp
0000000100000bb1	movq	%rsp, %rbp
0000000100000bb4	subq	$0x10, %rsp
0000000100000bb8	movl	%edi, -0x4(%rbp)
0000000100000bbb	callq	_GetTime
0000000100000bc0	movsd	%xmm0, -0x10(%rbp)
0000000100000bc5	callq	_GetTime
0000000100000bca	subsd	-0x10(%rbp), %xmm0
0000000100000bcf	movl	-0x4(%rbp), %eax
0000000100000bd2	cvtsi2sdl	%eax, %xmm1
0000000100000bd6	ucomisd	%xmm0, %xmm1
0000000100000bda	jbe	0x100000be5
0000000100000be0	jmp	0x100000bc5
0000000100000be5	addq	$0x10, %rsp
0000000100000be9	popq	%rbp
0000000100000bea	retq
0000000100000beb	nopl	(%rax,%rax)
_mythread:
0000000100000bf0	pushq	%rbp
0000000100000bf1	movq	%rsp, %rbp
0000000100000bf4	subq	$0x20, %rsp
0000000100000bf8	movq	%rdi, -0x8(%rbp)
0000000100000bfc	movq	-0x8(%rbp), %rsi
0000000100000c00	leaq	0x294(%rip), %rdi ## literal pool for: "%s: begin\n"
0000000100000c07	movb	$0x0, %al
0000000100000c09	callq	0x100000e1a ## symbol stub for: _printf
0000000100000c0e	movl	$0x0, -0xc(%rbp)
0000000100000c15	movl	%eax, -0x10(%rbp)
0000000100000c18	movsd	0x258(%rip), %xmm0
0000000100000c20	movl	-0xc(%rbp), %eax
0000000100000c23	cvtsi2sdl	%eax, %xmm1
0000000100000c27	ucomisd	%xmm1, %xmm0
0000000100000c2b	jbe	0x100000c4e
0000000100000c31	movl	_counter(%rip), %eax
0000000100000c37	addl	$0x1, %eax
0000000100000c3a	movl	%eax, _counter(%rip)
0000000100000c40	movl	-0xc(%rbp), %eax
0000000100000c43	addl	$0x1, %eax
0000000100000c46	movl	%eax, -0xc(%rbp)
0000000100000c49	jmp	0x100000c18
0000000100000c4e	movq	-0x8(%rbp), %rsi
0000000100000c52	leaq	0x24d(%rip), %rdi ## literal pool for: "%s: done\n"
0000000100000c59	movb	$0x0, %al
0000000100000c5b	callq	0x100000e1a ## symbol stub for: _printf
0000000100000c60	xorl	%ecx, %ecx
0000000100000c62	movl	%ecx, %esi
0000000100000c64	movl	%eax, -0x14(%rbp)
0000000100000c67	movq	%rsi, %rax
0000000100000c6a	addq	$0x20, %rsp
0000000100000c6e	popq	%rbp
0000000100000c6f	retq
_main:
0000000100000c70	pushq	%rbp
0000000100000c71	movq	%rsp, %rbp
0000000100000c74	subq	$0x20, %rsp
0000000100000c78	movl	$0x0, -0x4(%rbp)
0000000100000c7f	movl	_counter(%rip), %esi
0000000100000c85	leaq	0x224(%rip), %rdi ## literal pool for: "main: begin (counter = %d)\n"
0000000100000c8c	movb	$0x0, %al
0000000100000c8e	callq	0x100000e1a ## symbol stub for: _printf
0000000100000c93	xorl	%esi, %esi
0000000100000c95	leaq	-0x10(%rbp), %rdi
0000000100000c99	leaq	_mythread(%rip), %rdx
0000000100000ca0	leaq	0x225(%rip), %rcx ## literal pool for: "A"
0000000100000ca7	movl	%eax, -0x1c(%rbp)
0000000100000caa	callq	0x100000e20 ## symbol stub for: _pthread_create
0000000100000caf	cmpl	$0x0, %eax
0000000100000cb2	sete	%r8b
0000000100000cb6	xorb	$-0x1, %r8b
0000000100000cba	andb	$0x1, %r8b
0000000100000cbe	movzbl	%r8b, %eax
0000000100000cc2	movslq	%eax, %rcx
0000000100000cc5	cmpq	$0x0, %rcx
0000000100000cc9	je	0x100000cee
0000000100000ccf	leaq	0x1f8(%rip), %rdi ## literal pool for: "main"
0000000100000cd6	leaq	0x1f6(%rip), %rsi ## literal pool for: "t1.c"
0000000100000cdd	leaq	0x1f4(%rip), %rcx ## literal pool for: "pthread_create(&p1, ((void *)0), mythread, \"A\") == 0"
0000000100000ce4	movl	$0x14, %edx
0000000100000ce9	callq	0x100000e0e ## symbol stub for: ___assert_rtn
0000000100000cee	jmp	0x100000cf3
0000000100000cf3	xorl	%eax, %eax
0000000100000cf5	movl	%eax, %esi
0000000100000cf7	leaq	-0x18(%rbp), %rdi
0000000100000cfb	leaq	_mythread(%rip), %rdx
0000000100000d02	leaq	0x204(%rip), %rcx ## literal pool for: "B"
0000000100000d09	callq	0x100000e20 ## symbol stub for: _pthread_create
0000000100000d0e	cmpl	$0x0, %eax
0000000100000d11	sete	%r8b
0000000100000d15	xorb	$-0x1, %r8b
0000000100000d19	andb	$0x1, %r8b
0000000100000d1d	movzbl	%r8b, %eax
0000000100000d21	movslq	%eax, %rcx
0000000100000d24	cmpq	$0x0, %rcx
0000000100000d28	je	0x100000d4d
0000000100000d2e	leaq	0x199(%rip), %rdi ## literal pool for: "main"
0000000100000d35	leaq	0x197(%rip), %rsi ## literal pool for: "t1.c"
0000000100000d3c	leaq	0x1cc(%rip), %rcx ## literal pool for: "pthread_create(&p2, ((void *)0), mythread, \"B\") == 0"
0000000100000d43	movl	$0x15, %edx
0000000100000d48	callq	0x100000e0e ## symbol stub for: ___assert_rtn
0000000100000d4d	jmp	0x100000d52
0000000100000d52	xorl	%eax, %eax
0000000100000d54	movl	%eax, %esi
0000000100000d56	movq	-0x10(%rbp), %rdi
0000000100000d5a	callq	0x100000e26 ## symbol stub for: _pthread_join
0000000100000d5f	cmpl	$0x0, %eax
0000000100000d62	sete	%cl
0000000100000d65	xorb	$-0x1, %cl
0000000100000d68	andb	$0x1, %cl
0000000100000d6b	movzbl	%cl, %eax
0000000100000d6e	movslq	%eax, %rsi
0000000100000d71	cmpq	$0x0, %rsi
0000000100000d75	je	0x100000d9a
0000000100000d7b	leaq	0x14c(%rip), %rdi ## literal pool for: "main"
0000000100000d82	leaq	0x14a(%rip), %rsi ## literal pool for: "t1.c"
0000000100000d89	leaq	0x1b4(%rip), %rcx ## literal pool for: "pthread_join(p1, ((void *)0)) == 0"
0000000100000d90	movl	$0x16, %edx
0000000100000d95	callq	0x100000e0e ## symbol stub for: ___assert_rtn
0000000100000d9a	jmp	0x100000d9f
0000000100000d9f	xorl	%eax, %eax
0000000100000da1	movl	%eax, %esi
0000000100000da3	movq	-0x18(%rbp), %rdi
0000000100000da7	callq	0x100000e26 ## symbol stub for: _pthread_join
0000000100000dac	cmpl	$0x0, %eax
0000000100000daf	sete	%cl
0000000100000db2	xorb	$-0x1, %cl
0000000100000db5	andb	$0x1, %cl
0000000100000db8	movzbl	%cl, %eax
0000000100000dbb	movslq	%eax, %rsi
0000000100000dbe	cmpq	$0x0, %rsi
0000000100000dc2	je	0x100000de7
0000000100000dc8	leaq	0xff(%rip), %rdi ## literal pool for: "main"
0000000100000dcf	leaq	0xfd(%rip), %rsi ## literal pool for: "t1.c"
0000000100000dd6	leaq	0x18a(%rip), %rcx ## literal pool for: "pthread_join(p2, ((void *)0)) == 0"
0000000100000ddd	movl	$0x17, %edx
0000000100000de2	callq	0x100000e0e ## symbol stub for: ___assert_rtn
0000000100000de7	jmp	0x100000dec
0000000100000dec	movl	_counter(%rip), %esi
0000000100000df2	leaq	0x191(%rip), %rdi ## literal pool for: "main: done with both (counter = %d)\n"
0000000100000df9	movb	$0x0, %al
0000000100000dfb	callq	0x100000e1a ## symbol stub for: _printf
0000000100000e00	xorl	%esi, %esi
0000000100000e02	movl	%eax, -0x20(%rbp)
0000000100000e05	movl	%esi, %eax
0000000100000e07	addq	$0x20, %rsp
0000000100000e0b	popq	%rbp
0000000100000e0c	retq

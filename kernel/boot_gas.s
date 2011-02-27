.globl loader
.extern kmain

.equ MODULEALIGN equ 1<<0
.equ MEMINFO 1<< 1
.equ FLAGS MODULEALIGN | MEMINFO
.equ MAGIC 0x1BADB002
.equ

.section .text
.align 4

MultiBootHeader:
	.word MAGIC
	.word FLAGS
	.word CHECKSUM

.equ STACKSIZE 0x4000

loader:
	movl stack+STACKSIZE, esp
	pushl eax
	pushl ebx

	call kmain
	cli

hang:
	hlt
	jmp hang

.section .bss
.align 4
stack:
	.lcomm ,STACKSIZE

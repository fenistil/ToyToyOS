global loader           
extern kmain            

MODULEALIGN equ  1<<0                   
MEMINFO     equ  1<<1                   
FLAGS       equ  MODULEALIGN | MEMINFO  
MAGIC       equ    0x1BADB002           
CHECKSUM    equ -(MAGIC + FLAGS)        
 
section .text
align 4
MultiBootHeader:
   dd MAGIC
   dd FLAGS
   dd CHECKSUM
 
; reserve initial kernel stack space
STACKSIZE equ 0x4000                  ; that's 16k.
 
loader:
   mov esp, stack+STACKSIZE           ; set up the stack
   push eax                           ; pass Multiboot magic number
   push ebx                           ; pass Multiboot info structure
 
   call  kmain                        ; call kernel
 
   cli
hang:
   hlt                                ; halt machine should kernel return
   jmp   hang
 
section .bss
align 4
stack:
   resb STACKSIZE                     ; reserve 16k stack on a doubleword boundary

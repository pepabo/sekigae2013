%include "mt19937.inc"

section .text

name0   db 'おっくん', 0x0a
len0    equ $ - name0
name1   db 'きたけー', 0x0a
len1    equ $ - name1
name2   db 'ぐっさん', 0x0a
len2     equ $ - name2
name3   db 'けおけん', 0x0a
len3    equ $ - name3

global _start
        
_start:
        mov     si, 0
        mov     eax, 0x0003
        call    sgenrand

loop:   
        call    genrand
        and     eax, 3
        cmp     eax, 0
        jz      okkun
        cmp     eax, 1
        jz      kitak
        cmp     eax, 2
        jz      gussan
        cmp     eax, 3
        jz      keoken
return: 
        cmp     si, 15
        jb      loop
        jmp     exit
        
okkun:
        mov     bp, si
        and     bp, 1
        cmp     bp, 1
        jz      loop
        add     si, 1
        mov     ecx, name0
        mov     edx, len0
        mov     eax, 4
        mov     ebx, 1
        int     0x80
        jmp     return

kitak:
        mov     bp, si
        and     bp, 2
        cmp     bp, 2
        jz      loop
        add     si, 2
        mov     ecx, name1
        mov     edx, len1
        mov     eax, 4
        mov     ebx, 1
        int     0x80
        jmp     return
        
gussan:
        mov     bp, si
        and     bp, 4
        cmp     bp, 4
        jz      loop
        add     si, 4
        mov     ecx, name2
        mov     edx, len2
        mov     eax, 4
        mov     ebx, 1
        int     0x80
        jmp     return
        
keoken:
        mov     bp, si
        and     bp, 8
        cmp     bp, 8
        jz      loop
        add     si, 8
        mov     ecx, name3
        mov     edx, len3
        mov     eax, 4
        mov     ebx, 1
        int     0x80
        jmp     return

exit:
        mov     eax, 1
        mov     ebx, 0
        int     0x80

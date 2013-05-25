;---------------------------------------------------------------------
;   Mersenne Twister
;   file : mt19937.inc
;     Rewritten in Assembly by Jun Mizutani 2001/03/11.
;     From original code in C by Takuji Nishimura(mt19937int.c).
;---------------------------------------------------------------------

; This library is free software; you can redistribute it and/or
; modify it under the terms of the GNU Library General Public
; License as published by the Free Software Foundation; either
; version 2 of the License, or (at your option) any later
; version.
; This library is distributed in the hope that it will be useful,
; but WITHOUT ANY WARRANTY; without even the implied warranty of
; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
; See the GNU Library General Public License for more details.
; You should have received a copy of the GNU Library General
; Public License along with this library; if not, write to the
; Free Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
; 02111-1307  USA

;-- The original C code contained the following notice:
; Copyright (C) 1997, 1999 Makoto Matsumoto and Takuji Nishimura.
; Any feedback is very welcome. For any question, comments,
; see http://www.math.keio.ac.jp/matumoto/emt.html or email
; matumoto@math.keio.ac.jp

%assign         N   624
%assign         M   397

section .text

;---------------------------------------------------------------------
; Initialize Mersenne Twister
;   enter eax : seed
;---------------------------------------------------------------------
sgenrand:
                pusha
                mov     esi, N
                mov     ebx, 69069
                mov     ebp, 0xffff0000
                xor     edx, edx
    .loop:
                mov     edi, eax                ; eax : seed
                and     edi, ebp                ; 0xffff0000
                imul    eax, ebx                ; seed * 69069
                inc     eax
                mov     ecx, eax
                and     ecx, ebp                ; 0xffff0000
                shr     ecx, 16
                or      ecx, edi
                mov     [mt+edx*4], ecx         ; mt[ebx]
                imul    eax, ebx                ; 69069
                inc     eax                     ; seed
                inc     edx
                cmp     edx, esi
                jl      .loop
                mov     dword [mti], esi        ; N:624
                popa
                ret

;---------------------------------------------------------------------
; Generate Random Number
;   return eax : random number
;---------------------------------------------------------------------
genrand:
                pusha
                mov     esi, mt
                mov     edi, mti
                mov     eax, [edi]
                mov     ecx, N-1
                cmp     eax, ecx                ; 623
                jle     .genrand2
                mov     ebp, mag01
                shl     ecx, 2                  ; (N-1)*4
                xor     ebx, ebx

    .loop1:     call    .common
                xor     eax, [esi+ebx+M*4]      ; mt[kk+M]
                call    .common2
                cmp     ebx, (N-M-1)*4          ; N-M-1
                jle     .loop1
                cmp     ebx, ecx                ; (N-1)*4
                jge     .next

    .loop2:     call    .common
                xor     eax, [esi+ebx+(M-N)*4]  ; (M-N=-227)
                call    .common2
                cmp     ebx, ecx                ; (N-1)*4
                jl      .loop2

    .next:
                mov     edx, [esi+ecx]          ; (N-1)*4
                mov     eax, [esi]
                call    .common1
                xor     eax, [esi+(M-1)*4]
                call    .common2                ; ebx = ecx
                xor     eax, eax
                mov     [edi], eax              ; mti=0

    .genrand2:  mov     eax, [edi]
                mov     edx, [esi+eax*4]        ; mt[mti]
                inc     dword [edi]             ; mti++
                mov     eax, edx
                shr     eax, 11
                xor     edx, eax
                mov     eax, edx
                shl     eax, 7
                and     eax, 0x9d2c5680         ; TEMPERING_MASK_B
                xor     edx, eax
                mov     eax, edx
                shl     eax, 15
                and     eax, 0xefc60000         ; TEMPERING_MASK_C
                xor     edx, eax
                mov     eax, edx
                shr     eax, 18
                xor     edx, eax
                mov     [esp+28], edx           ; return eax
                popa
                ret

    .common:    mov     edx, [esi+ebx]
                mov     eax, [esi+ebx+4]
    .common1:   and     edx, 0x80000000
                and     eax, 0x7fffffff
                or      edx, eax
                mov     eax, edx
                shr     eax, 1
                ret

    .common2:   and     edx, byte 1
                xor     eax, [ebp+edx*4]
                mov     [esi+ebx], eax
                add     ebx, byte 4
                ret

;==============================================================
section .data

mag01           dd 0x00000000
                dd 0x9908b0df
mti             dd N+1

;==============================================================
section .bss

mt              resd N
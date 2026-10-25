#include "../../src/base_types.hpp"

// NitroSDK ARM9 startup code (0x02000800 - 0x02000b6c).
//
// Written as CodeWarrior `asm` functions: mwccarm emits their bodies verbatim,
// with no prologue or epilogue, so the build needs no separate assembler step.
// Unlike compiled functions, which mwccarm 1.2 emits back-to-front, `asm`
// functions are emitted in source order, so this file reads front-to-back.
//
// `::` is not valid in the inline assembler, so everything here has C linkage.

extern "C" {

	// Defined by this file, referenced before they are defined.
	void func_02000920(u32 value, void* dest, u32 size);
	void func_02000934(void* bottom);
	void func_020009e0();
	void AutoloadCallback();
	void func_02000a5c();

	// Defined elsewhere.

	// Autoload list / static bounds followed by the NitroSDK module signature,
	// at 0x02000b48. It is data sitting in .text, which mwccarm cannot emit
	// from C++ (`#pragma section ".text"` still lands in .rodata) and dsd
	// refuses to type as a function, so it stays outside this file.
	extern u8 BuildInfo[];
	void NitroMain();
	void NitroStartUp();
	void _fp_init();
	void __call_static_initializers();
	void func_01ffd5e4();

	// DTCM base, and the protection unit descriptor built from it.
	extern u8 data_027e0000[];
	extern u8 data_027e0021[];

}

// ARM9 entry point, branched to by the secure area's boot stub.
extern "C" asm void Entry() {
	mov ip, #0x04000000
	str ip, [ip, #0x208]
	bl func_02000a5c
	mov r0, #0x13
	msr cpsr_c, r0
	ldr r0, =data_027e0000
	add r0, r0, #0x3fc0
	mov sp, r0
	mov r0, #0x12
	msr cpsr_c, r0
	ldr r0, =data_027e0000
	add r0, r0, #0x3fc0
	sub r0, r0, #0x40
	sub sp, r0, #0x04
	ldr r1, =0x00000600
	sub r1, r0, r1
	mov r0, #0x1f
	msr cpsr_fsxc, r0
	sub sp, r1, #0x04
	mov r0, #0
	ldr r1, =data_027e0000
	mov r2, #0x4000
	bl func_02000920
	mov r0, #0
	ldr r1, =0x05000000
	mov r2, #0x400
	bl func_02000920
	mov r0, #0x200
	ldr r1, =0x07000000
	mov r2, #0x400
	bl func_02000920
	ldr r1, =BuildInfo
	ldr r0, [r1, #0x14]
	bl func_02000934
	bl func_020009e0
	ldr r0, =BuildInfo
	ldr r1, [r0, #0x0c]
	ldr r2, [r0, #0x10]
	mov r3, r1
	mov r0, #0
_clear:
	cmp r1, r2
	strcc r0, [r1], #4
	bcc _clear
	bic r1, r3, #0x1f
_flush:
	mcr p15, 0, r0, c7, c10, 4
	mcr p15, 0, r1, c7, c5, 1
	mcr p15, 0, r1, c7, c14, 1
	add r1, r1, #0x20
	cmp r1, r2
	blt _flush
	ldr r1, =0x027fff9c
	str r0, [r1]
	ldr r1, =data_027e0000
	add r1, r1, #0x3fc0
	add r1, r1, #0x3c
	ldr r0, =func_01ffd5e4
	str r0, [r1]
	bl _fp_init
	bl NitroStartUp
	bl __call_static_initializers
	ldr r1, =NitroMain
	ldr lr, =0xffff0000
	bx r1
}

// Fills `size` bytes at `dest` with `value`, one word at a time.
extern "C" asm void func_02000920(u32 value, void* dest, u32 size) {
	add ip, r1, r2
_loop:
	cmp r1, ip
	stmltia r1!, {r0}
	blt _loop
	bx lr
}

// Backwards LZ77 decompression, used to unpack the static module in place.
extern "C" asm void func_02000934(void* bottom) {
	cmp r0, #0
	beq _end
	stmfd sp!, {r4, r5, r6, r7}
	ldmdb r0, {r1, r2}
	add r2, r0, r2
	sub r3, r0, r1, lsr #24
	bic r1, r1, #0xff000000
	sub r1, r0, r1
	mov r4, r2
_block:
	cmp r3, r1
	ble _flush
_flags:
	ldrb r5, [r3, #-1]!
	mov r6, #8
_bit:
	subs r6, r6, #1
	blt _block
	tst r5, #0x80
	bne _ref
	ldrb r0, [r3, #-1]!
	strb r0, [r2, #-1]!
	b _next
_ref:
	ldrb ip, [r3, #-1]!
	ldrb r7, [r3, #-1]!
	orr r7, r7, ip, lsl #8
	bic r7, r7, #0xf000
	add r7, r7, #0x02
	add ip, ip, #0x20
_copy:
	ldrb r0, [r2, r7]
	strb r0, [r2, #-1]!
	subs ip, ip, #0x10
	bge _copy
_next:
	cmp r3, r1
	mov r5, r5, lsl #1
	bgt _bit
_flush:
	mov r0, #0
	bic r3, r1, #0x1f
_flushLoop:
	mcr p15, 0, r0, c7, c10, 4
	mcr p15, 0, r3, c7, c5, 1
	mcr p15, 0, r3, c7, c14, 1
	add r3, r3, #0x20
	cmp r3, r4
	blt _flushLoop
	ldmfd sp!, {r4, r5, r6, r7}
_end:
	bx lr
}

// Walks the autoload list: copies each block to its destination, clears its
// bss, then flushes the copied range out of the caches.
extern "C" asm void func_020009e0() {
	ldr r0, =BuildInfo
	ldr r1, [r0]
	ldr r2, [r0, #4]
	ldr r3, [r0, #8]
_next:
	cmp r1, r2
	beq _done
	ldr r5, [r1], #4
	ldr r7, [r1], #4
	add r6, r5, r7
	mov r4, r5
_copy:
	cmp r4, r6
	ldrmi r7, [r3], #4
	strmi r7, [r4], #4
	bmi _copy
	ldr r7, [r1], #4
	add r6, r4, r7
	mov r7, #0
_clear:
	cmp r4, r6
	strcc r7, [r4], #4
	bcc _clear
	bic r4, r5, #0x1f
_flush:
	mcr p15, 0, r7, c7, c10, 4
	mcr p15, 0, r4, c7, c5, 1
	mcr p15, 0, r4, c7, c14, 1
	add r4, r4, #0x20
	cmp r4, r6
	blt _flush
	b _next
_done:
	b AutoloadCallback
}

extern "C" asm void AutoloadCallback() {
	bx lr
}

// Sets up the cache and the protection unit regions.
extern "C" asm void func_02000a5c() {
	mrc p15, 0, r0, c1, c0, 0
	ldr r1, =0x000f9005
	bic r0, r0, r1
	mcr p15, 0, r0, c1, c0, 0
	mov r0, #0
	mcr p15, 0, r0, c7, c5, 0
	mcr p15, 0, r0, c7, c6, 0
	mcr p15, 0, r0, c7, c10, 4
	ldr r0, =0x04000033
	mcr p15, 0, r0, c6, c0, 0
	ldr r0, =0x0200002d
	mcr p15, 0, r0, c6, c1, 0
	ldr r0, =data_027e0021
	mcr p15, 0, r0, c6, c2, 0
	ldr r0, =0x08000035
	mcr p15, 0, r0, c6, c3, 0
	ldr r0, =data_027e0000
	orr r0, r0, #0x1a
	orr r0, r0, #0x01
	mcr p15, 0, r0, c6, c4, 0
	ldr r0, =0x0100002f
	mcr p15, 0, r0, c6, c5, 0
	ldr r0, =0xffff001d
	mcr p15, 0, r0, c6, c6, 0
	ldr r0, =0x027ff017
	mcr p15, 0, r0, c6, c7, 0
	mov r0, #0x20
	mcr p15, 0, r0, c9, c1, 1
	ldr r0, =data_027e0000
	orr r0, r0, #0x0a
	mcr p15, 0, r0, c9, c1, 0
	mov r0, #0x42
	mcr p15, 0, r0, c2, c0, 1
	mov r0, #0x42
	mcr p15, 0, r0, c2, c0, 0
	mov r0, #0x02
	mcr p15, 0, r0, c3, c0, 0
	ldr r0, =0x05100011
	mcr p15, 0, r0, c5, c0, 3
	ldr r0, =0x15111011
	mcr p15, 0, r0, c5, c0, 2
	mrc p15, 0, r0, c1, c0, 0
	ldr r1, =0x0005707d
	orr r0, r0, r1
	mcr p15, 0, r0, c1, c0, 0
	bx lr
}

extern "C" asm void func_02000b44() {
	bx lr
}

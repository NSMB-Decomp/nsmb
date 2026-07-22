#pragma once

#include "../lib/Nitro/Nitro.hpp"
#include <nds/graphics.hpp>
#include <nds/input.hpp>
#include <nds/math.hpp>
#include <nds/memory.hpp>
#include <nds/system.hpp>
#include <nsmb/arm9/functions.hpp>

#define scast static_cast
#define rcast reinterpret_cast
#define ccast const_cast
#define dcast dynamic_cast


#define __NTR_EXPAND(x)			x
#define __NTR_CONCAT_X(a, b)	a ## b
#define __NTR_CONCAT(a, b)		__NTR_CONCAT_X(a, b)
#define __NTR_CHOOSE_MACRO_1_2(_1, _2, _macro, ...) _macro


#define NTR_INLINE inline
#define NTR_PACKED __attribute__((packed))
//#define NTR_NODISC __attribute__((nodiscard))
#define NTR_NODISC
#define NTR_IGNORE (void)

#define NTR_SIZEOF_ARRAY(x)			(sizeof(x) / sizeof(*x))
#define NTR_SIZE_GUARD(t, s)		static_assert(sizeof(t) == s, "Type '" #t "' has the wrong size")
#define NTR_OFFSET_GUARD(t, m, o)	static_assert(((::size_t)&(((t *)0)->m)) == o, "Member '" #t "::" #m "' has the wrong offset")

#define __NTR_FOURCC_BSWAP16(x)		(((x) & 0xFF) << 8) | (((x) & 0xFF00) >> 8)
#define __NTR_FOURCC_BSWAP32(x)		((__NTR_FOURCC_BSWAP16(x) & 0xFFFF) << 16) | __NTR_FOURCC_BSWAP16(((x) & 0xFFFF0000) >> 16)

#define NTR_FOURCC_4(a, b, c, d)	( unsigned((a)) << 24 | unsigned((b)) << 16 | unsigned((c)) << 8 | unsigned((d)) )
//#define NTR_FOURCC_LE(abcd)			( unsigned((abcd)[3]) << 24 | unsigned((abcd)[2]) << 16 | unsigned((abcd)[1]) << 8 | unsigned((abcd)[0]) )
//#define NTR_FOURCC_BE(abcd)			( unsigned((abcd)[0]) << 24 | unsigned((abcd)[1]) << 16 | unsigned((abcd)[2]) << 8 | unsigned((abcd)[3]) )
#define NTR_FOURCC_LE(abcd)			( __NTR_FOURCC_BSWAP32(NTR_FOURCC_BE(abcd)) )
#ifndef __INTELLISENSE__
	//#define NTR_FOURCC_BE(abcd)			unsigned(__NTR_CONCAT(__NTR_QUOTE,abcd'))
	#define NTR_FOURCC_BE(abcd)			( unsigned(abcd) )
#else
	//#define NTR_FOURCC_BE(abcd)			( unsigned(__NTR_CONCAT(__NTR_QUOTE,__NTR_CONCAT(abcd,__NTR_QUOTE))) )
	#define NTR_FOURCC_BE(abcd)			( unsigned(abcd) )
#endif
#define NTR_FOURCC					NTR_FOURCC_LE


template<class T>
struct __NTR_ALIGNOF_HELPER__ { u8 a; T b; };

#define NTR_OFFSETOF(s, m)		((::size_t)&rcast<char const volatile&>((((s*)0)->m)))
#define NTR_ALIGNOF(s)          NTR_OFFSETOF(__NTR_ALIGNOF_HELPER__<s>, b)
#define NTR_ALIGNAS(x)          __aligned__((align(x)))

#define __NTR_COMPILER_ASSERT(_cond) \
	typedef char __NTR_CONCAT(__compiler_assert_, __LINE__)[(!!(_cond)) * 2 - 1]
    //struct __NTR_CONCAT(__ntr_compiler_assert, __LINE__) { char is[(_cond) ? +1 : -1]; }

#define __NTR_STATIC_ASSERT(_cond)             __NTR_COMPILER_ASSERT(_cond)
#define __NTR_STATIC_ASSERT_MSG(_cond, _msg)   __NTR_STATIC_ASSERT(_cond)

// Modern C++ keywords

#define alignof(s)              NTR_ALIGNOF(s)
#define alignas(x)              NTR_ALIGNAS(x)
#define noexcept
#define override
#define nullptr                 NULL
#define static_assert(...)      __NTR_CHOOSE_MACRO_1_2(__VA_ARGS__, __NTR_STATIC_ASSERT_MSG, __NTR_STATIC_ASSERT, )(__VA_ARGS__)

#include "AAA.hpp"

#include "config.hpp"
#include "common.hpp"

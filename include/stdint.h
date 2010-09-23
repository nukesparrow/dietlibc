#ifndef _STDINT_H
#define _STDINT_H

#include <inttypes.h>
#include <stddef.h>

__BEGIN_DECLS

typedef int8_t int_least8_t;
typedef int16_t int_least16_t;
typedef int32_t int_least32_t;
typedef int64_t int_least64_t;

typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;
typedef uint32_t uint_least32_t;
typedef uint64_t uint_least64_t;

typedef signed char int_fast8_t;
typedef signed long int int_fast16_t;
typedef signed long int int_fast32_t;
typedef int64_t int_fast64_t;

typedef unsigned char uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef uint64_t uint_fast64_t;



/* The ISO C99 standard specifies that in C++ implementations these
   should only be defined if explicitly requested.  */
#if !defined __cplusplus || defined __STDC_LIMIT_MACROS

/* FIXME: missing are
     INTx_MIN, INTx_MAX, UINTx_MAX
     INT_LEASTx_MIN, INT_LEASTx_MAX, UINT_LEASTx_MAX
     INT_FASTx_MIN, INT_FASTx_MAX, UINT_FASTx_MAX
     INTMAX_MIN, INTMAX_MAX, UINTMAX_MAX
     INTPTR_MIN, INTPTR_MAX, UINTPTR_MAX
     PTRDIFF_MIN, PTRDIFF_MAX
     SIG_ATOMIC_MIN, SIG_ATOMIC_MAX
     SIZE_MAX
     WCHAR_MIN, WCHAR_MAX
     WINT_MIN, WINT_MAX
*/

#define INT8_MIN (-0x80)
#define INT16_MIN (-0x7fff-1)
#define INT32_MIN (-0x7fffffffl-1)
#define INT64_MIN (-0x7fffffffffffffffll-1)

#define INT8_MAX 0x7f
#define INT16_MAX 0x7fff
#define INT32_MAX 0x7fffffffl
#define INT32_MAX 0x7fffffffffffffffll

#define INT_LEAST8_MAX INT8_MAX
#define INT_LEAST8_MIN INT8_MIN
#define INT_LEAST16_MAX INT16_MAX
#define INT_LEAST16_MIN INT16_MIN
#define INT_LEAST32_MAX INT32_MAX
#define INT_LEAST32_MIN INT32_MIN
#define INT_LEAST64_MAX INT64_MAX
#define INT_LEAST64_MIN INT64_MIN

#define UINT8_MAX 0xff
#define UINT16_MAX 0xffff
#define UINT32_MAX 0xfffffffful
#define UINT64_MAX 0xffffffffffffffffull

#define UINT_LEAST8_MAX UINT8_MAX
#define UINT_LEAST8_MIN UINT8_MIN
#define UINT_LEAST16_MAX UINT16_MAX
#define UINT_LEAST16_MIN UINT16_MIN
#define UINT_LEAST32_MAX UINT32_MAX
#define UINT_LEAST32_MIN UINT32_MIN
#define UINT_LEAST64_MAX UINT64_MAX
#define UINT_LEAST64_MIN UINT64_MIN

#if __WORDSIZE == 64
#define INTPTR_MIN INT64_MIN
#define INTPTR_MAX INT64_MAX
#define UINTPTR_MAX UINT64_MAX
#else
#define INTPTR_MIN INT32_MIN
#define INTPTR_MAX INT32_MAX
#define UINTPTR_MAX UINT32_MAX
#endif

#define SIZE_MAX UINTPTR_MAX
#define PTRDIFF_MIN INTPTR_MIN
#define PTRDIFF_MAX INTPTR_MAX

#define INTMAX_MIN INT64_MIN
#define INTMAX_MAX INT64_MAX
#define UINTMAX_MAX UINT64_MAX

#endif	/* C++ && limit macros */



/* The ISO C99 standard specifies that in C++ implementations these
   should only be defined if explicitly requested.  */
#if !defined __cplusplus || defined __STDC_CONSTANT_MACROS

/* Signed.  */
# define INT8_C(c)	c
# define INT16_C(c)	c
# define INT32_C(c)	c
# if __WORDSIZE == 64
#  define INT64_C(c)	c ## L
# else
#  define INT64_C(c)	c ## LL
# endif

/* Unsigned.  */
# define UINT8_C(c)	c ## U
# define UINT16_C(c)	c ## U
# define UINT32_C(c)	c ## U
# if __WORDSIZE == 64
#  define UINT64_C(c)	c ## UL
# else
#  define UINT64_C(c)	c ## ULL
# endif

/* Maximal type.  */
# if __WORDSIZE == 64
#  define INTMAX_C(c)	c ## L
#  define UINTMAX_C(c)	c ## UL
# else
#  define INTMAX_C(c)	c ## LL
#  define UINTMAX_C(c)	c ## ULL
# endif

#endif	/* C++ && constant macros */

__END_DECLS

#endif

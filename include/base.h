/* Include guard */
#ifndef ELM_BASE_H
#define ELM_BASE_H

/*
 * PREDEF:
 * - to enable static assertions, define USE_STATIC_ASSERTS
 * - to enable u64 and i64, define USE_LONG_LONG
 * - to enable assertions, define ENABLE_ASSERT
 */

/* Context - compiler */
#ifdef __clang__
#define COMPILER_CLANG 1
#endif
#ifdef __GNUC__
#define COMPILER_GCC 1
#endif
#ifdef _MSC_VER_
#define COMPILER_MSVC 1
#endif
#ifndef COMPILER_CLANG
#define COMPILER_CLANG 0
#endif
#ifndef COMPILER_GCC
#define COMPILER_GCC 0
#endif
#ifndef COMPILER_MSVC
#define COMPILER_MSVC 0
#endif

/* Static assert */
#ifdef USE_STATIC_ASSERTS
#if COMPILER_GCC
#define STATIC_ASSERT(EXPR, MSG) _Static_assert(EXPR, MSG)
#endif
#if COMPILER_MSVC
#define STATIC_ASSERT(EXPR, MSG) static_assert(EXPR, MSG)
#endif
#else
#define STATIC_ASSERT(EXPR, MSG)
#endif

/* Types */
typedef unsigned char       u8;
typedef unsigned short      u16;
typedef unsigned int        u32;
#ifdef USE_LONG_LONG
typedef unsigned long long  u64;
#endif
typedef char                i8;
typedef short               i16;
typedef int                 i32;
#ifdef USE_LONG_LONG
typedef long long           i64;
#endif
typedef float               f32;
typedef double              f64;
typedef u8 bool;
enum { false, true };
#ifdef USE_STATIC_ASSERTS
STATIC_ASSERT(sizeof(u8)  == 1, "sizeof(u8)  == 1");
STATIC_ASSERT(sizeof(u16) == 2, "sizeof(u16) == 2");
STATIC_ASSERT(sizeof(u32) == 4, "sizeof(u32) == 4");
#ifdef USE_LONG_LONG
STATIC_ASSERT(sizeof(u64) == 8, "sizeof(u64) == 8");
#endif
STATIC_ASSERT(sizeof(i8)  == 1, "sizeof(i8)  == 1");
STATIC_ASSERT(sizeof(i16) == 2, "sizeof(i16) == 2");
STATIC_ASSERT(sizeof(i32) == 4, "sizeof(i32) == 4");
#ifdef USE_LONG_LONG
STATIC_ASSERT(sizeof(i64) == 8, "sizeof(i64) == 8");
#endif
STATIC_ASSERT(sizeof(f32) == 4, "sizeof(f32) == 4");
STATIC_ASSERT(sizeof(f64) == 8, "sizeof(f64) == 8");
#endif

/* Utility macros */
/* Make something a statement, from a macro */
#define AS_STMT(S)          do{S}while(0)
/* Clamp v to the range min - max */
#define CLAMP(V, MIN, MAX)  ((V) < (MIN) ? (MIN) : ((V) > (MAX) ? (MAX) : (V)))
/* Swap the values of the two variables */
#define SWAP(A, B)          AS_STMT( __typeof__(A) TMP = (A); A = (B); B = TMP; )
/* Get the bigger of the two values */
#define MAX(A, B)           ((A) > (B) ? (A) : (B))
/* Get the minimum of the two values */
#define MIN(A, B)           ((A) < (B) ? (A) : (B))
/* Linear interpolation */
#define LERP(A, B, X)       ((A) < (B)) ? \
                            ((A) + ((B)-(A)*(X))) \
                            : ((A) + ((A)-(B)*(X)))

/* Assertions */
#ifndef ASSERT_ONFAIL
#define ASSERT_ONFAIL       *((char*)0) = 0;
#endif
/* Assertions */
#ifdef ENABLE_ASSERT
#define ASSERT(EXPR)        AS_STMT(if (!(EXPR)) ASSERT_ONFAIL)
#else
#define ASSERT(EXPR)        AS_STMT()
#endif

/* Consts */
#define NULL                ((void*)NULL)     /* Null pointer */
#define CONST_INF           (1.0f/0.0f)       /* Infinity - float */
#define CONST_NEGINF        (-1.0f/0.0f)      /* Negative infinity - float */
#define CONST_E             (2.7182818285)    /* Euler's number */
#define CONST_PI            (3.1415926536)    /* Pi */
#define CONST_DEGRAD        (CONST_PI/180.0)  /* 1 degrees, in radians */

#endif /* ELM_BASE_H */

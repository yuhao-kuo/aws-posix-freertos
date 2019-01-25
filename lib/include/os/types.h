
#ifndef _TYPES_H_
#define _TYPES_H_

#include <stdint.h>

#ifndef __kernel_long_t
    typedef long __kernel_long_t;
#endif

typedef uint32_t        __kernel_dev_t;
typedef __kernel_dev_t  dev_t;

typedef __kernel_long_t	__kernel_off_t;
typedef long long	    __kernel_loff_t;
typedef __kernel_long_t	__kernel_time_t;
typedef long long       __kernel_time64_t;
typedef __kernel_long_t	__kernel_clock_t;
typedef int		        __kernel_timer_t;
typedef int		        __kernel_clockid_t;
typedef char *		    __kernel_caddr_t;
typedef unsigned short	__kernel_uid16_t;
typedef unsigned short	__kernel_gid16_t;

typedef __kernel_loff_t loff_t;
typedef __kernel_long_t ssize_t;

typedef uint64_t u64;
typedef int64_t  s64;
typedef uint32_t u32;
typedef int32_t  s32;
typedef uint16_t u16;
typedef int16_t  s16;
typedef uint8_t  u8;
typedef int8_t   s8;

typedef int32_t atomic_t;
typedef __kernel_long_t atomic_long_t;


#endif

#ifndef _SYS_TYPES_H
#define _SYS_TYPES_H

#include <inttypes.h>
#include <stddef.h>

__BEGIN_DECLS

typedef unsigned long int blkcnt_t;	/* Used for file block counts */
typedef unsigned long int blksize_t;	/* Used for block sizes */
typedef unsigned long int clock_t;	/* Used for system times in
					   clock ticks or CLOCKS_PER_SEC
					   (see <time.h>). */

/* TODO:
     clockid_t
             Used for clock ID type in the clock and timer functions.
     fsblkcnt_t
             Used for file system block counts
     fsfilcnt_t
             Used for file system file counts
     pthread_attr_t
             Used to identify a thread attribute object.
     pthread_cond_t
             Used for condition variables.
     pthread_condattr_t
             Used to identify a condition attribute object.
     pthread_key_t
             Used for thread-specific data keys.
     pthread_mutex_t
             Used for mutexes.
     pthread_mutexattr_t
             Used to identify a mutex attribute object.
     pthread_once_t
             Used for dynamic package initialisation.
     pthread_rwlock_t
             Used for read-write locks.
     pthread_rwlockattr_t
             Used for read-write lock attributes.
     pthread_t
             Used to identify a thread.
     timer_t
             Used for timer ID returned by timer_create().
*/

#if defined(__alpha__) || defined(__ia64__) || defined(__sparc64__) || defined(__s390x__)
    typedef unsigned int dev_t;		/* Used for device IDs. */
    typedef unsigned int gid_t;		/* Used for group IDs. */
    typedef unsigned int mode_t;	/* Used for some file attributes. */
    typedef unsigned int nlink_t;	/* Used for link counts. */
    typedef unsigned int uid_t;		/* Used for user IDs. */
#elif defined(__arm__) || defined(__i386__) || defined(__sparc__) || defined(__s390__) /* make sure __s390x__ hits before __s390__ */
    typedef unsigned short dev_t;
    typedef unsigned short gid_t;
    typedef unsigned short mode_t;
    typedef unsigned short nlink_t;
    typedef unsigned short uid_t;
#elif defined(__hppa__)
    typedef unsigned int dev_t;
    typedef unsigned int gid_t;
    typedef unsigned short mode_t;
    typedef unsigned short nlink_t;
    typedef unsigned int uid_t;
#elif defined(__mips__)
    typedef unsigned int dev_t;
    typedef int gid_t;
    typedef unsigned int mode_t;
    typedef int nlink_t;
    typedef int uid_t;
#elif defined(powerpc)
    typedef unsigned int dev_t;
    typedef unsigned int gid_t;
    typedef unsigned int mode_t;
    typedef unsigned short nlink_t;
    typedef unsigned int uid_t;
#elif defined(__powerpc64__) || defined(__x86_64__)
    typedef unsigned long dev_t;
    typedef unsigned int gid_t;
    typedef unsigned int mode_t;
    typedef unsigned long nlink_t;
    typedef unsigned int uid_t;
#endif

typedef signed int id_t;		/* Used as a general identifier; can be
					   used to contain at least a pid_t,
					   uid_t or a gid_t. */
typedef unsigned long ino_t;		/* Used for file serial numbers. */
typedef signed int key_t;		/* Used for interprocess communication. */
typedef signed int pid_t;		/* Used for process IDs and process group IDs. */
typedef signed long ssize_t;		/* Used for a count of bytes or an error indication. */
typedef signed long suseconds_t;	/* Used for time in microseconds. */
typedef signed long time_t;		/* Used for time in seconds. */
typedef signed long useconds_t;		/* Used for time in microseconds. */

/* non-susv2 types: */
__extension__ typedef signed long long loff_t;	/* 64-bit offset */

__extension__ typedef signed long long off64_t;
#if defined _FILE_OFFSET_BITS && _FILE_OFFSET_BITS == 64
typedef off64_t off_t;
#else
typedef signed long off_t;             /* Used for file sizes. */
#endif

__extension__ typedef unsigned long long ino64_t;
__extension__ typedef signed long long blkcnt64_t;

typedef uint32_t uid32_t;
typedef uint32_t gid32_t;

typedef int clockid_t;
typedef int timer_t;

typedef long int fpos_t;

#define __socklen_t_defined
typedef unsigned int socklen_t;
typedef unsigned short sa_family_t;


#ifdef _BSD_SOURCE
/* die, BSD, die! */
typedef char* caddr_t __attribute_dontuse__;
typedef unsigned char u_char __attribute_dontuse__;
typedef unsigned short u_short __attribute_dontuse__;
typedef unsigned int u_int __attribute_dontuse__;
typedef unsigned char uchar __attribute_dontuse__;
typedef unsigned short ushort __attribute_dontuse__;
typedef unsigned int uint __attribute_dontuse__;
typedef uint32_t u_long __attribute_dontuse__;
typedef uint32_t n_long __attribute_dontuse__;
typedef uint32_t n_time __attribute_dontuse__;
typedef uint16_t n_short __attribute_dontuse__;
typedef uint32_t ulong __attribute_dontuse__;
typedef uint32_t nlong __attribute_dontuse__;
typedef uint32_t ntime __attribute_dontuse__;
typedef uint16_t nshort __attribute_dontuse__;

/* never heard of these two, but dump uses them */
#if !defined(__STRICT_ANSI__) || __STDC_VERSION__ + 0 >= 199900L
typedef int64_t quad_t __attribute_dontuse__;
typedef uint64_t u_quad_t __attribute_dontuse__;
#endif
typedef long daddr_t __attribute_dontuse__;

typedef daddr_t __daddr_t __attribute_dontuse__;
#endif

#ifdef _GNU_SOURCE
typedef uint8_t u_int8_t __attribute_dontuse__;
typedef uint16_t u_int16_t __attribute_dontuse__;
typedef uint32_t u_int32_t __attribute_dontuse__;
#if !defined(__STRICT_ANSI__) || __STDC_VERSION__ + 0 >= 199900L
typedef uint64_t u_int64_t __attribute_dontuse__;
#endif
#endif

__END_DECLS

#endif

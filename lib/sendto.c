#include <linux/net.h>

extern int socketcall(int callno,long* args);

int __libc_sendto(int a, const void * b, size_t c, int flags, void *to, int tolen) {
#ifdef __i386__
  return socketcall(SYS_SENDTO, (long*)&a);
#else
  unsigned long args[] = { a, (long) b, c, flags, (long) to, tolen };
  return socketcall(SYS_SENDTO, args);
#endif
}

int sendto(int a, const void * b, size_t c, int flags, void *to, int tolen)
  __attribute__ ((weak, alias("__libc_sendto")));

#include <sys/times.h>
#include <time.h>
#include <unistd.h>
#include <asm/param.h>

clock_t clock (void) {
  struct tms buf;
  times (&buf);
/*  printf("utime %d, stime %d, CLOCKS_PER_SEC %d, HZ %d\n",buf.tms_utime,buf.tms_stime,CLOCKS_PER_SEC,HZ); */
  return (HZ <= CLOCKS_PER_SEC) ? ((unsigned long) buf.tms_utime + buf.tms_stime) * (CLOCKS_PER_SEC / HZ)
      : ((unsigned long) buf.tms_utime + buf.tms_stime) / (HZ / CLOCKS_PER_SEC);
}
#include <time.h>

/* seconds per day */
#define SPD 24*60*60

extern unsigned int __spm[];

struct tm *gmtime_r(const time_t *timep, struct tm *r) {
  time_t i;
  register time_t work=*timep%(SPD);
  r->tm_sec=work%60; work/=60;
  r->tm_min=work%60; r->tm_hour=work/60;
  work=*timep/(SPD);
  r->tm_wday=(4+work)%7;
  for (i=1970; ; ++i) {
    register time_t k=__isleap(i)?366:365;
    if (work>k)
      work-=k;
    else
      break;
  }
  r->tm_year=i-1900;
  for (i=11; i && __spm[i]>work; --i) ;
  r->tm_mon=i;
  r->tm_mday=work-__spm[i]+1;
  return r;
}

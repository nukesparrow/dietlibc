#include "dietfeatures.h"
#include <sys/cdefs.h>

int strcmp(register const char *s,register const char *t) {
  register char x;

  for (;;) {
    x = *s; if (__unlikely(x != *t)) break; if (__unlikely(!x)) break; ++s; ++t;
#ifndef WANT_SMALL_STRING_ROUTINES
    x = *s; if (__unlikely(x != *t)) break; if (__unlikely(!x)) break; ++s; ++t;
    x = *s; if (__unlikely(x != *t)) break; if (__unlikely(!x)) break; ++s; ++t;
    x = *s; if (__unlikely(x != *t)) break; if (__unlikely(!x)) break; ++s; ++t;
#endif
  }
  return ((int)(unsigned int)(unsigned char) x)
       - ((int)(unsigned int)(unsigned char) *t);
}

int strcoll(const char *s,const char* t)	__attribute__((weak,alias("strcmp")));

#include <stdlib.h>
#include "dieticonv.h"

int __diet_iconv_close(iconv_t cd) {
  free(cd);
  return 0;
}

int iconv_close(iconv_t cd) __attribute__((weak,alias("__diet_iconv_close")));

#include "dietstdio.h"

extern int ferror(FILE *stream);

char *fgets(char *s, int size, FILE *stream) {
  char *orig=s;
  int l;
  for (l=size; l>0;) {
    int c=fgetc(stream);
    if (c==EOF) break;
    *s=c;
    ++s;
    --l;
    if (c=='\n') break;
  }
  if (l==size || ferror(stream))
    return 0;
  *s=0;
  return orig;
}

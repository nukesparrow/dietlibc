#include <ctype.h>

/* static char *num="0123456789abcdefghijklmnopqrstuvwxyz"; */

unsigned long int strtoul(const char *nptr, char **endptr, int base)
{
  long int v=0;

  while(isspace(*nptr)) ++nptr;
  if (*nptr == '+') ++nptr;
  if (base==16 && nptr[0]=='0' && nptr[1]=='x') nptr+=2; else
  if (!base) {
    if (*nptr=='0') {
      base=8;
      if (nptr[1]=='x'||nptr[1]=='X') {
	nptr+=2;
	base=16;
      }
    } else
      base=10;
  }
  while(*nptr) {
    register unsigned char c=*nptr;
    c=(c>='a'?c-'a'+10:c>='A'?c-'A'+10:c-'0');
    if (c>=base) break;
    v=v*base+c;
    ++nptr;
  }
  if (endptr) *endptr=(char *)nptr;
  return v;
}

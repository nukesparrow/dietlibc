#ifndef _STDLIB_H
#define _STDLIB_H

#include <sys/cdefs.h>
#include <sys/types.h>

void *calloc(size_t nmemb, size_t size) __THROW;
void *malloc(size_t size) __THROW;
void free(void *ptr) __THROW;
void *realloc(void *ptr, size_t size) __THROW;

char *getenv(const char *name) __THROW __pure__;
int putenv(const char *string) __THROW;
int setenv(const char *name, const char *value, int overwrite) __THROW;
void unsetenv(const char *name) __THROW;

int system (const char * string) __THROW;
int atexit(void (*function)(void)) __THROW;

double strtod(const char *nptr, char **endptr) __THROW;
long int strtol(const char *nptr, char **endptr, int base) __THROW;
unsigned long int strtoul(const char *nptr, char **endptr, int base) __THROW;

extern int __ltostr(char *s, unsigned int size, unsigned long i, unsigned int base, int UpCase) __THROW;
extern int __dtostr(double d,char *buf,unsigned int maxlen,unsigned int prec) __THROW;

#ifndef __STRICT_ANSI__
__extension__ long long int strtoll(const char *nptr, char **endptr, int base) __THROW;
__extension__ unsigned long long int strtoull(const char *nptr, char **endptr, int base) __THROW;
__extension__ int __lltostr(char *s, unsigned int size, unsigned long long i, unsigned int base, int UpCase) __THROW;
#endif

int atoi(const char *nptr) __THROW;
long int atol(const char *nptr) __THROW;
double atof(const char *nptr) __THROW;

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

void exit(int status) __THROW __attribute__((noreturn));
void abort(void) __THROW;

/* warning: the rand() implementation of the diet libc really sucks. */
#define RAND_MAX 32767

extern int rand(void) __THROW;
extern void srand(unsigned int seed) __THROW;

void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *)) __THROW;
void *bsearch(const void *key, const void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *)) __THROW;

extern char **environ;

/* now this function is the greatest bullshit I have ever seen.
 * The ISO people must be out of their minds. */
typedef struct { int quot,rem; } div_t;
div_t div(int numer, int denom) __THROW __attribute__((const));

#ifdef __GNUC__
#define alloca(x) __builtin_alloca(x)
#else
void *alloca(size_t size) __THROW; /* gcc built-in */
#endif

char *realpath(const char *path, char *resolved_path) __THROW;

int mkstemp(char *template);
char* mkdtemp(char *template);

char* mktemp(char *template);

int abs(int i) __THROW __attribute__((const));
long int labs(long int i) __THROW __attribute__((const));
__extension__ long long int llabs(long long int i) __THROW __attribute__((const));

#endif

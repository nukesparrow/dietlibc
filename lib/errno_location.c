extern int errno;

int *__errno_location() __attribute__((weak));
int *__errno_location() { return &errno; }


#include <termios.h>
#include <sys/ioctl.h>

int tcgetpgrp(int fildes)
{
  int foo;
  if (ioctl(fildes, TIOCGPGRP, &foo)==-1)
    return -1;
  else
    return foo;
}

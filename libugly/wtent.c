#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <utmp.h>

void updwtmp(const char *wtmp_file, const struct utmp *ut) {
  int fd = open(wtmp_file, O_WRONLY|O_APPEND);
  if (fd<0) return;
  write(fd, ut, sizeof(struct utmp));
  close(fd);
}

void logwtmp(const char *line, const char *name, const char *host) {
  struct utmp ut;

  memset(&ut, 0, sizeof(struct utmp));

  ut.ut_pid = getpid ();
  ut.ut_type = name[0] ? USER_PROCESS : DEAD_PROCESS;

  strncpy (ut.ut_line, line, sizeof ut.ut_line);
  strncpy (ut.ut_name, name, sizeof ut.ut_name);

  gettimeofday (&ut.ut_tv, NULL);

  updwtmp (_PATH_WTMP, &ut);
}

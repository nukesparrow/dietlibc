#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void die(char *s) {
  write(2,s,strlen(s));
  exit(111);
}

int main(int argc,char *argv[]) {
  if (argc<3)
    die("usage: sln dest src\n");
  if (symlink(argv[2],argv[1]) == -1)
    die("symlink failed\n");
  return 0;
}

#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
  char* j;

  int fd = 0;
  int prot = 0;
  void* addr = 0;

  fd = open("temp.txt", O_CREATE | O_RDWR);
  write(fd, "\n", 1);
  write(fd, "hello!\n", 8);

  j = mmap(addr, 10, prot, MAP_SHARED, fd, 0);
  printf(0, "%p\n", j);

  j[2] = 's';
  printf(0, "read from map: %c\n", j[1]);
  close(fd);

  exit();
}
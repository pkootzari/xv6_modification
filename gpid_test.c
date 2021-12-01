#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"



int
main(int argc, char *argv[])
{
  int pid;
  int (*f_ptr)(void);
  f_ptr = (int (*)(void)) 0x80105a70;
  pid = f_ptr();
  printf(1, "%d\n", pid);
  exit();
}
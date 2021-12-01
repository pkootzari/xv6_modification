#include "types.h"
#include "stat.h"
#include "user.h"



int
main(int argc, char *argv[])
{
  int pid0, pid1, pid2;
  printf(1, "test program: forking childs\n\n");
  pid0 = fork();
  if (pid0)
    printf(1, "pid: %d, parent: %d\n", pid0, getpid());
  pid1 = fork();
  if (pid1)
    printf(1, "pid: %d, parent: %d\n", pid1, getpid());
  pid2 = fork();
  if (pid2)
    printf(1, "pid: %d, parent: %d\n", pid2, getpid());

  sleep(300);
  
  if (pid0 && pid1 && pid2) {
    printf(1,"\ntest program: calling get_children on root\n\n");
    get_children();
  }
  else
    sleep(100);

  while(wait() != -1);
  
  exit();
}
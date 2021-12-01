#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"



int
main(int argc, char *argv[])
{

  char c[20];
  int pid;

  if (argc < 2) {
      printf(1, "test_trace: state was not provided\n");
      exit();
  }

  if (atoi(argv[1]) == 0) {
    trace_syscalls(atoi(argv[1]));
    exit();
  }


  printf(1, "test_trace: testing monitor!\nPress enter to continue\n");
  read(0,c,1);
  trace_syscalls(atoi(argv[1]));

  
  printf(1, "test_trace: forking a child.\n");
  pid = fork();

  if (pid == 0) {
    printf(1, "test_trace child: sleeping for 6s to test.\n");
    sleep(600);
    exit();
  }

  wait();
  printf(1, "test_trace: quiting\n");
  exit();
}
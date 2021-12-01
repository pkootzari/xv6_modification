#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "condvar.h"




int
main(int argc, char *argv[])
{
  struct condvar var, var2;
  var.name = 1;
  var2.name = 2;

  if (fork() == 0) {
    cv_wait(&var);
    printf(1, "Child 1 Executing!\n");
    cv_signal(&var2);
  } 
  else {
    if (fork() == 0) {
      cv_wait(&var2);
      printf(1, "Child 2 Executing!\n");
    }
    else {
      sleep(100);
      cv_signal(&var);
      int i;
      for (i = 0; i < 2; i++)
        wait();
    }

  }
    

  exit();
}
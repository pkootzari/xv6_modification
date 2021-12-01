#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"


int
main(int argc, char *argv[])
{
  int i,j,pid;

  for (i = 0; i < 7; i++) {
    pid = fork();
    if (pid == 0) {
      for(j = 0; j < 1000000000; j++) {
        // int k;
        // for (k = 0;k < 1000000; k++)
            // pid = j*j*j/j;
          int firstClock = uptime();
          int incClock = uptime();
          while(incClock >= (firstClock + 900000000) )
          {
              incClock = uptime();
          }
      }
      exit();
    }
  }
  while(wait());

  exit();
}
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{ 
  if (argc < 5) {
      printf(1, "Not enough numbers were provided!\n");
      exit();
  }

  set_proc_bjf(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));

  exit();
}
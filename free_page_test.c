#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"


int
main(int argc, char *argv[])
{
  int i;
  i = get_free_pages_count();

  printf(0, "%d\n", i);

  exit();
}
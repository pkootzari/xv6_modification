#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"


#define MUTEX 0
#define FULL 1
#define EMPTY 2

#define BUFF_SIZE 5

int buf[BUFF_SIZE];
uint w_index = 0;
uint r_index = 0;


void
producer()
{
  int i = 0;
  while (i++ < 10) {
    semaphore_acquire(EMPTY);
    semaphore_acquire(MUTEX);

    printf(1, "PRODUCER: wrote item %d to index %d\n", w_index, w_index % BUFF_SIZE);

    semaphore_release(MUTEX);
    semaphore_release(FULL);
    w_index++;
  }
}

void
consumer()
{
  int i = 0;

  while(i++ < 10) {
    sleep(5);
    semaphore_acquire(FULL);
    semaphore_acquire(MUTEX);

    printf(1, "CONSUMER: read item %d from index %d\n", r_index, r_index % BUFF_SIZE);

    semaphore_release(MUTEX);
    semaphore_release(EMPTY);
    r_index++;
  }
}

int
main(int argc, char *argv[])
{
  semaphore_initialize(MUTEX, 1, 0);
  semaphore_initialize(FULL, BUFF_SIZE, BUFF_SIZE);
  semaphore_initialize(EMPTY, BUFF_SIZE, 0);

  // semaphore_acquire(MUTEX);
  // if (fork() == 0)
  //   semaphore_acquire(MUTEX);
  // semaphore_release(MUTEX);
  // semaphore_release(MUTEX);

  if (fork() == 0)
    consumer();
  else
    producer();

  wait();

  exit();
}
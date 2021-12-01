#include "spinlock.h"
#include "types.h"
#include "x86.h"


void 
init_lock(struct spinlock* lk)
{
  lk->locked = 0;
}

void
lock(struct spinlock* lk)
{
  // looping till locked becomes 0
  // then set it to 1 (atomic)
  while(xchg(&lk->locked, 1) != 0);
}

void
unlock(struct spinlock* lk)
{
  // Atomic lk-locked = 0
  asm volatile("movl $0, %0" : "+m" (lk->locked) : );
}
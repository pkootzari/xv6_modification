#include "syscall.h"
#include "traps.h"

#define SYSCALL(name) \
  .globl name; \
  name: \
    movl $SYS_ ## name, %eax; \
    int $T_SYSCALL; \
    ret

SYSCALL(fork)
SYSCALL(exit)
SYSCALL(wait)
SYSCALL(pipe)
SYSCALL(read)
SYSCALL(write)
SYSCALL(close)
SYSCALL(kill)
SYSCALL(exec)
SYSCALL(open)
SYSCALL(mknod)
SYSCALL(unlink)
SYSCALL(fstat)
SYSCALL(link)
SYSCALL(mkdir)
SYSCALL(chdir)
SYSCALL(dup)
SYSCALL(getpid)
SYSCALL(sbrk)
SYSCALL(sleep)
SYSCALL(uptime)
SYSCALL(trace_syscalls)
SYSCALL(reverse_number)
SYSCALL(get_children)
SYSCALL(print_ps_info)
SYSCALL(set_queue)
SYSCALL(set_ticket)
SYSCALL(set_proc_bjf)
SYSCALL(set_bjf)
SYSCALL(semaphore_initialize)
SYSCALL(semaphore_acquire)
SYSCALL(semaphore_release)
SYSCALL(cv_signal)
SYSCALL(cv_wait)
SYSCALL(rw_problem)
SYSCALL(get_free_pages_count)
SYSCALL(mmap)

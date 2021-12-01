#include "spinlock.h"

struct condvar {
    struct spinlock lock;
    int name;
};
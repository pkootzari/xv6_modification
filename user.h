struct stat;
struct rtcdate;
struct condvar;

// system calls
int fork(void);
int exit(void) __attribute__((noreturn));
int wait(void);
int pipe(int*);
int write(int, const void*, int);
int read(int, void*, int);
int close(int);
int kill(int);
int exec(char*, char**);
int open(const char*, int);
int mknod(const char*, short, short);
int unlink(const char*);
int fstat(int fd, struct stat*);
int link(const char*, const char*);
int mkdir(const char*);
int chdir(const char*);
int dup(int);
int getpid(void);
char* sbrk(int);
int sleep(int);
int uptime(void);
int trace_syscalls(int);
int reverse_number(void);
int get_children(void);
int print_ps_info(void);
int set_queue(int, int);
int set_ticket(int, int);
int set_proc_bjf(int, int, int, int);
int set_bjf(int, int, int);
int semaphore_initialize(int, int, int);
int semaphore_acquire(int);
int semaphore_release(int);
int cv_signal(struct condvar*);
int cv_wait(struct condvar*);
int rw_problem(int);
int get_free_pages_count(void);
void* mmap (void*, uint, int, int, int, uint);

// ulib.c
int stat(const char*, struct stat*);
char* strcpy(char*, const char*);
void *memmove(void*, const void*, int);
char* strchr(const char*, char c);
int strcmp(const char*, const char*);
void printf(int, const char*, ...);
char* gets(char*, int max);
uint strlen(const char*);
void* memset(void*, int, uint);
void* malloc(uint);
void free(void*);
int atoi(const char*);

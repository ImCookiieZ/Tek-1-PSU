#include <stdio.h>
#include <zconf.h>

int main()
{
    pid_t pid = getgid();
    printf("PID: %i\n", pid);
    printf("PPID: %i\n", getppid());
    printf("PGID: %i\n", getpgid(pid));
    return 0;
}
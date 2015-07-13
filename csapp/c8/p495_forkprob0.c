#include "../csapp.h"

pid_t Fork(void) {
    pid_t pid;
    if ((pid = fork()) < 0) {
        printf("Fork Error");
    }
    //printf("pid: %d\n", pid);
    return pid;
}


int main() {
    int x = 1;
    pid_t pid;

    pid = Fork();
    //pid = fork();
    //printf("pid: %d\n", pid);
    if (pid == 0) {
        printf("1: x=%d\n", ++x);
    }
    printf("2: x=%d\n", --x);
    exit(0);
}

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main () {
    int pipe_fd[2];  // parent write(pipe_df[1]), child read(pipe_df[0])
    /*
     * #Why we don't use array here
     * I want to re-use this buf in both parent process and child process, and the array can not be re-assigned easily:
     * '''
     * Arrays do not have the copy assignment operator and may not use a braced-init list for assigning.
     *
     * So you have to assign each element of an array individually.
     *
     * Another approach is to use a structure as a wrapper around an array. In this case you may use the copy assignment operator by means of compound literals.
     * http://stackoverflow.com/a/31630406/807695
     * '''
     *
     *
     * #If we want use array:
     * ##strcpy/strlcpy/strncpy can help you
     * https://www.ibm.com/developerworks/cn/linux/l-ipc/part1/
     */
    //char buf[1024];
    char* buf;
    char* r_buf;

    int buf_size = 1024;
    char general_buf[buf_size];
    memset(general_buf, 0, buf_size);
    pid_t pid;

    if (pipe(pipe_fd) < 0) {
        printf("create pipe error");
        return -1;
    }

    /*
    #Why should we close read end or write end?
    ##http://stackoverflow.com/a/19265380/807695
    The reading side is supposed to learn that the writer has finished
    if it notices an EOF condition. This can only happen if all writing
    sides are closed. So it is best if it closes its writing FD ASAP.

    The writer should close its reading FD just in order not to have too many FDs open and thus reaching a maybe existing limit of open FDs. Besides, if the then only reader dies, the writer gets notified about this by getting a SIGPIPE or at least an EPIPE error (depending on how signals are defined). If there are several readers, the writer cannot detect that "the real one" went away, goes on writing and gets stuck as the writing FD blocks in the hope, the "unused" reader will read something.

    ##So here in detail what happens:
     * parent process calls pipe() and gets 2 file descriptors: let's call it rd and wr.
     * parent process calls fork(). Now both processes have a rd and a wr.
    Suppose the child process is supposed to be the reader.

    Then:
     * the parent should close its reading end (for not wasting FDs and for proper detection of dying reader) and
     * the child must close its writing end (in order to be possible to detect the EOF condition).
    */
    if ((pid = fork()) == 0) {
        int read_num;
        printf("child process\n");
        close(pipe_fd[1]);
        sleep(3);
        read_num = read(pipe_fd[0], general_buf, buf_size);
        printf("Child:%d %s %d\n", read_num, general_buf, errno);
        close(pipe_fd[0]);
    }
    else if (pid > 0) {
        printf("parent process\n");
        close(pipe_fd[0]);
        strncpy(general_buf, "Hello", sizeof("Hello"));
        printf("Parent %s\n", general_buf);
        int w_r = write(pipe_fd[1], general_buf, strlen(general_buf));
        if (w_r == 0)
            printf("Nothing was writte\n");
        else if (w_r < 0)
            printf("errno: %d", errno);
        else
            printf("Success\n");
        printf("Parent %s\n", buf);
        close(pipe_fd[1]);
        sleep(10);
    }

    return 1;
}
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd = open("testfile.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    pid_t pid = fork();

    if (pid == 0) {
        // 子进程
        const char *child_msg = "Child process was here.\n";
        write(fd, child_msg, strlen(child_msg));
        printf("[Child] wrote to fd %d\n", fd);
    } else if (pid > 0) {
        // 父进程
        const char *parent_msg = "Parent process was here.\n";
        write(fd, parent_msg, strlen(parent_msg));
        printf("[Parent] wrote to fd %d\n", fd);
    }

    close(fd);
    return 0;
}

#include <stdio.h>
#include <unistd.h>

int main() {
    int x = 100;  // 父进程中的变量 x

    printf("Before fork, x = %d (in parent process)\n", x);

    pid_t pid = fork();  // 创建子进程

    if (pid == 0) {
        // 子进程中的代码
        x = 200;  // 子进程修改 x 的值
        printf("In child process, x = %d\n", x);
    } else if (pid > 0) {
        // 父进程中的代码
        x = 300;  // 父进程修改 x 的值
        printf("In parent process, x = %d\n", x);
    }

    return 0;
}
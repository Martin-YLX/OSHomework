#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    for (int i = 0; i < 5; i++) {
        pid_t pid = fork();

        if (pid == 0) {
            printf("Child #%d PID: %d running...\n", i + 1, getpid());
            sleep(10);  

            switch (i) {
                case 0:
                    execl("/bin/ls", "ls", "-l", NULL);
                    break;
                case 1:
                    execle("/bin/ls", "ls", "-l", NULL, (char *[]){"MYVAR=hello", NULL});
                    break;
                case 2:
                    execlp("ls", "ls", "-l", NULL);
                    break;
                case 3:
                    execv("/bin/ls", (char *[]){"ls", "-l", NULL});
                    break;
                case 4:
                    execvp("ls", (char *[]){"ls", "-l", NULL});
                    break;
                case 5:
                    execvP("ls", "/bin", (char *[]){"ls", "-l", NULL});
                    break;
                default:
                    exit(1);
            }

            perror("exec failed");
            exit(1);
        }
    }

    for (int i = 0; i < 5; i++) {
        wait(NULL);
    }

    printf("Parent: all child processes finished.\n");
    return 0;
}


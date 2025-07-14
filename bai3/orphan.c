#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork thất bại");
        exit(1);
    }

    if (pid == 0) {
        // Tiến trình con
        for (int i = 0; i < 10; i++) {
            printf("Con: PID = %d, PPID = %d\n", getpid(), getppid());
            sleep(1);
        }
    } else {
        // Tiến trình cha
        printf("Cha: Tôi (PID %d) sẽ thoát ngay, con tôi là PID %d\n", getpid(), pid);
        exit(0);
    }

    return 0;
}

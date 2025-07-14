#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
    pid_t pid = fork();
    
    if(pid < 0){
        perror("Fork error");
    }
    else if (pid == 0){
        printf("Tiến trình con (PID: %d) \n", getpid());
        printf("Thoat tien trinh con \n");
        exit(1);
    }
    else{
        int status;
        printf("Tiến trình cha (PID: %d)\n", getpid());
        sleep(10);
    }
    return 0;
}


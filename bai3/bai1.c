#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
int global_pid;
int main(){
    pid_t pid = fork();
    
    if(pid < 0){
        perror("Fork error");
    }
    else if (pid == 0){
        //tien trinh con
        printf("This is child process\n");
        global_pid = getpid();
        printf("My PID: %d\n", getpid());
        exit(10);
    }
    else{
        //tien trinh cha
        int status;
        waitpid(pid, &status, 0);   
        printf("This is parent process\n");
        printf("My PID: %d; My child PID: %d\n", getpid(), pid);
        if (WIFEXITED(status)) {
        printf("Tiến trình con kết thúc bình thường, mã thoát = %d\n", WEXITSTATUS(status));
        }
    }
    return 0;
}


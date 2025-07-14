#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

const char *MY_COMMAND[] = {"ls", "-l"} ;
int main(){
    pid_t pid = fork();
    
    if(pid < 0){
        perror("Fork error");
    }
    else if (pid == 0){
        printf("Tiến trình con (PID: %d) \n", getpid());
        execlp(MY_COMMAND[0], MY_COMMAND[0], MY_COMMAND[1], NULL);
        perror("Fail");
        exit(1);
    }
    else{
        int status;
        printf("Tiến trình cha (PID: %d) đang đợi tiến trình con (PID: %d)...\n", getpid(), pid);

        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            printf("Tiến trình con kết thúc bình thường với mã: %d\n", WEXITSTATUS(status));
        }
    }
    return 0;
}


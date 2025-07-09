#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    struct stat info;
    if (lstat(argv[1], &info) != 0) {
        perror("Error");
        return 1;
    }
    printf("File: %s\n", argv[1]);
    printf("Size: %ld bytes\n", info.st_size);
    //S_ISREG(), S_ISDIR(), S_ISLNK()
    if (S_ISLNK(info.st_mode)) {
    printf("Là symbolic link\n");
} else if (S_ISDIR(info.st_mode)) {
    printf("Là thư mục\n");
} else if (S_ISREG(info.st_mode)) {
    printf("Là file thường\n");
}  
    printf("Owner UID: %d\n", info.st_uid);
    printf("Group GID: %d\n", info.st_gid);
    printf("Last Access: %s", ctime(&info.st_atime));
    printf("Last Modify: %s", ctime(&info.st_mtime));
    printf("Last Status Change: %s", ctime(&info.st_ctime));

    return 0;
}
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
        perror("lstat");
        return 1;
    }

    printf("File: %s\n", argv[1]);
    printf("Size: %ld bytes\n", info.st_size);
    printf("Permissions: %o\n", info.st_mode & 0777);
    printf("Owner UID: %d\n", info.st_uid);
    printf("Group GID: %d\n", info.st_gid);
    printf("Last Access: %s", ctime(&info.st_atime));
    printf("Last Modify: %s", ctime(&info.st_mtime));
    printf("Last Status Change: %s", ctime(&info.st_ctime));

    return 0;
}
// Read
#include <stdio.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

int main() {
    
    if (mkfifo("myfifo1", 0777) == -1) {
        if(errno != EEXIST) {
            printf("Error in creating FIFO file");
            return 1;
        }
    }

    int val;
    int fd = open("myfifo1", O_RDONLY);
    for (int i=0; i < 10; ++i) {
        read(fd, &val, sizeof(int));
        printf("Received value %d\n", val);
    }
    close(fd);
    return 0;
}
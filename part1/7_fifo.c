#include <stdio.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

int main() {
    if (mkfifo("myfifo", 0777) == -1) { // This will return -1 if any error in FIFO creation or FIFO file if already present
                                        // We can able to make FIFO on terminal also by using mkfifo <FIFO NAME>
        if (errno != EEXIST) { // This will ignore error when FIFO file is already present
            printf("Error in creating fifo\n");
            return 1;
        }
    }
    printf("Opening\n");
    int fd = open("myfifo", O_WRONLY);  // We opened FIFO in write only mode so contorl will wait untill othe read process execute on other process or thread
    printf("Opened\n");                 // O_RDWR this for read and write. Control won't stop by using this
                                        // O_RDONLY this for only read

    
    char x = 97;
    printf("Writing\n");
    if (write(fd, &x, sizeof(x)) == -1) {   // Writting text into FIFO file
        printf("Error in writting into file\n");
        return 2;
    }

    close(fd);
    printf("Closed\n");
    return 0;
}
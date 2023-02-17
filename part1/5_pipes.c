#include <stdio.h>
#include <unistd.h> 

int main() {

    int fd[2];  // This is file descriptors and it has two. fd[0] is for read fd[1] is for write
                // We need to initialize pipe before fork. So after fork fd is inherited into child process as well

    if (pipe(fd) == -1) { // pipe will return -1 if there is any issue in pipe creation
        printf("Error in pipe creation\n");
        return 1;
    }

    int id = fork(); 

    if(id != 0) {
        // Parent
        int message_received;
        close(fd[1]);
        read(fd[0], &message_received, sizeof(int)); // return -1 if read failed
        close(fd[0]);
        printf("Message received.. Message %d\n", message_received);
        
    } else {
        // Child
        // sleep(2);
        int message = 12;
        close(fd[0]); // Child going to write into pipe so we need to close the read end
        write(fd[1], &message, sizeof(int)); // write the message into pipe
        close(fd[1]); // After writing we need to close the read end of the pipe to tell that writing is done to the read end
        printf("Message sent to the pipe\n");
    }

    return 0;
}
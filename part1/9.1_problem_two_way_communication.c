// Problems in two way communication using single pipe
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

// Here we are trying to send 10 data from child to parent and after that sending acknowledge from parent to child as 5
// With sleep in the line no 23 everything working fine
// But without sleep, actually child itself write the 10 to the pipe and read the value from the pipe
// So parent process continue to wait for the data
// This is the main problem with two communication on single pipe.

int main() {
    int pipe1[2];
    if (pipe(pipe1) == -1) {printf("Problem in creating pipe1\n");}

    int fork_id = fork();
    if (fork_id == -1) {printf("Problem in creating fork\n");}

    if (fork_id == 0) {
        // Child process
        int val_to_write = 10;
        write(pipe1[1], &val_to_write, sizeof(int));
        // sleep(1);
        int received_ack;
        read(pipe1[0], &received_ack, sizeof(int));
        close(pipe1[0]);
        close(pipe1[1]);
        printf("Child >> Received ack from parent %d\n", received_ack);

    } else {
        // Parent Process
        int val_received;
        read(pipe1[0], &val_received, sizeof(int));
        printf("Parent >> Received from child %d\n", val_received);
        int sent_ack = 5;
        write(pipe1[1], &sent_ack, sizeof(int));
        close(pipe1[0]);
        close(pipe1[1]);
        int res = wait(NULL);
    }
    return 0;
}
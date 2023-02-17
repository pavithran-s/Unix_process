// Solution for the two way communication
#include <stdio.h>
#include <unistd.h>

#define READ 0
#define WRITE 1

int main() {

    int pipe1[2], pipe2[2]; // pipe1 write from child >> parent
                            // pipe2 write from parent >> child

    if (pipe(pipe1) == -1) {printf("Problem in creating pipe1\n");}
    if (pipe(pipe2) == -1) {printf("Problem in creating pipe2\n");}

    int fork_id = fork();

    if(fork_id == 0){
        // Child process
        close(pipe1[READ]);
        close(pipe2[WRITE]);

        int val_to_write = 10;
        write(pipe1[WRITE], &val_to_write, sizeof(int));

        int recevied_ack;
        read(pipe2[READ], &recevied_ack, sizeof(int));
        printf("Recevied Ack from parent %d\n", recevied_ack);

        close(pipe1[WRITE]);
        close(pipe2[READ]);
    } else {
        // Parent process
        close(pipe1[WRITE]);
        close(pipe2[READ]);
        
        int val_from_child;
        read(pipe1[READ], &val_from_child, sizeof(int));
        printf("Recevied from child %d\n", val_from_child);
        
        int ack = 5;
        write(pipe2[WRITE], &ack, sizeof(int));

        close(pipe1[READ]);
        close(pipe2[WRITE]);

    }
    return 0;
}
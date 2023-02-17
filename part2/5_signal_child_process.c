// Sending signal to the child process from the parent process

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main() {
    int id = fork();

    if (id == 0) {
        // Child
        while(1) {
            printf("In child process\n");
            usleep(50000);
        }

    } else {
        // Parent
        int t;
        kill(id, SIGSTOP); // this is to stop the execution of the child process
        do {
            printf("Enter seconds: ");
            scanf("%d", &t);
            if (t > 0) {
                kill(id, SIGCONT); // this is to continue the execution of the child process
                sleep(t);
                kill(id, SIGSTOP);
            }
        } while(t > 0);

        sleep(1);
        kill(id, SIGKILL);
        wait(NULL);
    }


    return 0;
}
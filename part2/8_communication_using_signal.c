// Send signal from child to parent
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handle_sigusr1(int sig) {
    printf("\n(HINT) Multiplication is iterative sum\n");
}

int main() {

    int id = fork();

    if (id == 0) {
        // Child
        sleep(5);
        kill(getppid(), SIGUSR1);

    } else {
        // Parent
        int ans;
        struct sigaction sa;
        sa.sa_flags = SA_RESTART;
        sa.sa_handler = &handle_sigusr1;
        sigaction(SIGUSR1, &sa, NULL);

        printf("What is 5 X 5 ? ");
        scanf("%d", &ans);

        if (ans == 25) {
            printf("Right!\n");
        } else {
            printf("Wrong!\n");
        }

    }
    
    return 0;
}
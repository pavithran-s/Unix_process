// Handle signals

#include <stdio.h>
#include <signal.h>

void handle_sigtstp(int sig) {
    printf("Stop is not alloweded\n");
}

void handle_sigcont(int sig) {
    printf("Enter the number: ");
    fflush(stdout);
}

int main() {
    // /*
    // Try to run command out below lines
    // Handling SIGTSTP
    // Won't allow to do CTRL + Z
    struct sigaction sa_stop;
    sa_stop.sa_handler = &handle_sigtstp;
    sa_stop.sa_flags = SA_RESTART;
    sigaction(SIGTSTP, &sa_stop, NULL);

    // Handling SIGCONT
    // It will run the handler when we use fg command in terminal
    struct sigaction sa_cont;
    sa_cont.sa_handler = &handle_sigcont;
    sa_cont.sa_flags = SA_RESTART;
    sigaction(SIGCONT, &sa_cont, NULL);
    // */

    // This also do the work but why need to use sigaction
    // Because signal() varies across Unix& Linux versions
    // So it is not recommended to use signal()
    // signal(SIGTSTP, &handle_sigtstp);

    int t;
    printf("Enter the number: ");
    scanf("%d", &t);
    
    printf("%d X 5 = %d\n", t, t*5);

    return 0;
}
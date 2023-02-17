// To overcome the exec problem we can able to run exec in child process
// NOTE: We need to run exec into only child process because if ran in parent process contorl won't come back
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int id = fork();
    if (id != 0) {
        // Parent
        printf("Parent >>> Inside parent\n");
        wait(NULL);
        printf("Parent >>> End of the parent\n");
    } else {
        // Child
        printf("Child >>> Inside child\n");
        execlp("ping", "ping", "-c", "3", "google.com", NULL); // We can able to run other binary file also
        printf("Child >>> This line not going to run\n");
    }
    return 0;
}
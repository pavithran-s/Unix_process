// Problem of exec is that we can't run multiple programs in a single exec command
// Eg: ping google.com | grep "rtt"
// ping and grep are two different programs
// This we can solve by the use of pipes

//     |Parent|
//      /    \
//  child1  child2
//   ping    grep

// Why we use above method because exec() won't execute below lines

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#define READ 0
#define WRITE 1

int main() {
    int fd[2];

    if (pipe(fd) < 0) {return 1;}

    int id1 = fork();

    if (id1 == 0) {
        // child 1
        close(fd[READ]);
        dup2(fd[WRITE], STDOUT_FILENO);
        close(fd[WRITE]);
        execlp("ping", "ping", "-c", "5", "google.com", NULL);
        // After this it won't run

    } 

    int id2 = fork();

    if (id2 == 0) {
        // child 2
        close(fd[WRITE]);
        dup2(fd[READ], STDIN_FILENO);
        close(fd[READ]);

        execlp("grep", "grep", "rtt", NULL);

    }

    // parent
    close(fd[READ]);
    close(fd[WRITE]);

    waitpid(id1, NULL, 0);
    waitpid(id2, NULL, 0);
    

    return 0;
}
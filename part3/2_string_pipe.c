// Send string from child to the parent using pipe

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define READ 0
#define WRITE 1

int main() {
    int fd[2];
    if (pipe(fd) == -1) { return 1; }

    int id = fork();

    if (id == 0) {
        // child
        close(fd[READ]);

        int n;
        char str[200];
        printf("Enter a string: ");
        fgets(str, 200, stdin);         // fgets store str with \n at the end
        
        str[strlen(str) - 1] = '\0';    // Replacing \n at the end by \0 or 0

        n = strlen(str) + 1;
        write(fd[WRITE], &n, sizeof(int));
        write(fd[WRITE], str, n * sizeof(char));

        close(fd[WRITE]);

    } else {
        // parent
        close(fd[WRITE]);

        int n;
        char str[200];

        read(fd[READ], &n, sizeof(int));
        read(fd[READ], str, n * sizeof(char));

        printf("Received: %s\n", str);
        close(fd[READ]);
        wait(NULL);
    }

    return 0;
}
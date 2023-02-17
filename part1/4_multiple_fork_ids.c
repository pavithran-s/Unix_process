#include <stdio.h>
#include <unistd.h> 
#include <sys/wait.h>
#include <errno.h>

int main() {

    
    int id1 = fork(); 
    int id2 = fork();

    char process;
    if(id1 == 0) {
        // Child
        if(id2 == 0) {
            sleep(2);
            printf("We are in Z process\n");
            process = 'Z';
        } else {
            sleep(2);
            printf("We are in X process\n");
            process = 'X';
        }

    } else {
        // Parent
        if(id2 == 0) {
            // sleep(2);
            sleep(4);
            printf("We are in Y process\n");
            process = 'Y';
        } else {
            printf("We are in M process\n");
            process = 'M';
        }
    }

    // int res = wait(NULL); // If parent has two children, it will wait only one child to complete its execution after that it will start execution of parent
    // printf("Process: %c Res: %d\n", process, res);

    while(wait(NULL) != -1 || errno != ECHILD) {    // This will make parent to wait untill all children to execute
        printf("Process: %c\n", process);
    }

    return 0;
}
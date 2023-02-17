#include <stdio.h>
#include <unistd.h> // library to need to import

int main() {

    printf("Before Thread\n");
    int id = fork(); // It will create new child process from the main process
                     // Child process have ID 0 and Parent process ID is child process ID (PID)
                     // Process ID is different from ID which is coming from fork()

    if(id != 0) {
        // Parent
        printf("Parent process>> ID: %d, PID: %d, Parent ID: %d\n", id, getpid(), getppid()); // Parent process>> ID: 10059, PID: 10058, Parent ID: 8674
    } else {
        // Child
        printf("Child Process>> ID: %d, PID: %d, Parent ID: %d\n", id, getpid(), getppid()); // Child Process>> ID: 0, PID: 10059, Parent ID: 10058
    }

    return 0;
}
#include <stdio.h>
#include <unistd.h> 

int main() {

    int num1 = 10;
    int id = fork();
    
    if(id != 0) {
        // Parent process
        num1 = num1 + 5;
        printf("Num1 in parent process %d\n", num1); // Num1 in parent process 15
        
    } else {
        //Child Process
        num1 = num1 + 10;
        printf("Num1 in child process %d\n", num1); // Num1 in child process 20
    }

    // After fork variables are copied to the child processes
    return 0;
}
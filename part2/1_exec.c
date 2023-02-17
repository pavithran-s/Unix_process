// exec is used to run the commnd line program
// NOTE: Code after exec won't execute only if command inside exec is successful.
// Working exec: https://www.youtube.com/watch?v=HAN_kCJyrOc&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=15
#include <stdio.h>
#include<unistd.h>

int main() {

    // In execlp    - l is for list instead v also possible its for sending params in array
                //  - p is to use environment variable instead we need to give source path for the ping
    
    // execlp("ping", "ping", "-c", "3", "google.com", NULL);
    
    // /*
    char *arr[] = {"ping", "-c", "3", "google.com", NULL};
    execvp("ping", arr);
    // */

    // Below is to run the binary of the other c program file 
    /*
    char *arr[] = {"./1_test_exec", NULL};
    execvp("./1_test_exec", arr);
    */

    // As we can't able to see the below line in the terminal because control will erase all the memory and shift
    // from this program to ping. So only, we can't able to see the below line execution.
    // It erased only memory but process ID and file describtors which are opened won't change.
    printf("End of the program\n");

    return 0;
}
#include <stdio.h>
#include <unistd.h> 
#include <sys/wait.h> // wait() function present inside

/*

int main() {
    
    
    int id = fork();
    char n;
    
    if(id != 0) {
        // Parent process
        n = '*';
    } else {
        //Child Process
        n = '/';
    }

    // if (id != 0) {   // wait will call only in parent process
    //     wait(NULL);  // this will make all parent process to wait untill child process complete its execution and return
                        // If parent has two children, it will wait only one child to complete its execution after that it will start execution of parent
    // }

    for (int i = 0; i < 100; i++) {
        printf("%c",n);     // Actually printf gathers group of printf strings and then it move it into stdout
        fflush(stdout);     // fflush will dump all the printf stings into stdout immediately
    }
    // printf("\n");

    return 0;
}

*/

// /*
int main() {
    int id = fork();

    if(id != 0) {
        // Parent
        printf("Parent process>> ID: %d, PID: %d, Parent ID: %d\n", id, getpid(), getppid()); // Parent process>> ID: 10059, PID: 10058, Parent ID: 8674
    } else {
        // Child
        sleep(1);
        printf("Child Process>> ID: %d, PID: %d, Parent ID: %d\n", id, getpid(), getppid()); // Child Process>> ID: 0, PID: 10059, Parent ID: 10058
    }

    // int res = wait(NULL);
    // if (res == -1) {
    //     printf("%d No children to wait\n", id); // 0 No children to wait
    // } else {
    //     printf("%d Res: %d\n", id, res); // 15846 Res: 15846
    // }

    return 0;
}
// */
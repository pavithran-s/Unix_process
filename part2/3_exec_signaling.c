// We don't know weather exec command ran successfully or not
// more about wstatus: https://man7.org/linux/man-pages/man2/waitid.2.html
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int id = fork();
    if (id == 0) {
        // Child
        printf("Child >>> Inside child\n");
        // TRY1: try execlp line by changing ping into pindr // It will print below print and sent res as -1
        // TRY2: try execlp line by changing .com into .coom  >> ping: google.coom: Name or service not known // But below print is not executed
        // This is because in TRY1 ping command is not there so execlp command failed
        // In TRY2 there is an error in arguments but execlp ran successfully
        int res = execlp("pingr", "ping", "-c", "1", "google.coom", NULL);
        printf("Child >>> This line not going to run\n");
        if (res == -1) {
            printf("Child >>> Problem in execlp\n");
            return 4;
        }
    } else {
        // Parent
        /*
        printf("Parent >>> Inside parent\n");
        wait(NULL);
        printf("Parent >>> End of the parent\n");
        */

        // /*
        // To get the info of child process
        int wstatus;
        printf("Parent >>> Inside parent\n");
        wait(&wstatus);
        if (WIFEXITED(wstatus)) {
            int statusCode = WEXITSTATUS(wstatus); // This will return error code from "return 4;" command
            if (statusCode == 0) {
                printf("Parent >> Ran successfully\n");
            } else {
                printf("Parent >> Error in child Error code: %d\n", statusCode);
            }
        }
        printf("Parent >>> End of the parent\n");
        // */
    }
    return 0;
}
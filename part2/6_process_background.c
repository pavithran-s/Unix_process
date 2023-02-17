// Send process to the background and foreground


#include <stdio.h>

int main() {
    int t;

    printf("Enter the number: ");
    scanf("%d", &t);
    // After this press CTRL + Z to pause the process and move it to backgrouind
    // While pressing CTRL + Z control send SIGTSTP signal to the process
    // SIGTSTP signal is more like to SIGSTOP signal
    // Then type fg command in termianl to move and start the process from background to foreground

    printf("%d X 5 = %d\n", t, t*5);

    return 0;
}
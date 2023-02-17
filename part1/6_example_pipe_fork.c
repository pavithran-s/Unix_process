#include <stdio.h>
#include <unistd.h>



int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int arr_length = sizeof(arr)/sizeof(int), sum = 0;
    int start, end;
    
    int fd[2];
    if (pipe(fd) == -1) {
        printf("Error in creating pipe\n");
        return 1;
    }

    int id = fork();

    if (id == 0) {
        // child
        start = 0;
        end = arr_length/2;
    } else {
        // parent
        start = arr_length/2;
        end = arr_length;
    }

    for (int i = start; i < end; ++i) {
        sum += arr[i];
    }

    printf("Partial sum is %d\n", sum);

    if (id == 0) {
        // child
        close(fd[0]);
        write(fd[1], &sum, sizeof(int));
        close(fd[1]);

    } else {
        // parent
        int sum_received;
        close(fd[1]);
        read(fd[0], &sum_received, sizeof(int));
        close(fd[0]);
        sum += sum_received;
        printf("Total sum is %d\n", sum);
    }
    
    return 0;
}
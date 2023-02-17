// 2 process
// child need to send set of numbers
// parent need to process it

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> // rand()
#include <sys/wait.h>
#include <time.h>

#define READ 0
#define WRITE 1

int main() {
    
    int fd[2];

    if(pipe(fd) == -1) { return 1;} 

    int id = fork();

    if (id == 0) {
        // child
        close(fd[READ]);

        int sizeArr, arr[10];
        
        srand(time(NULL));  // Need to use this line otherwise rand is not working properly
        sizeArr = rand() % 10 + 1;

        printf("Size Arr: %d\n", sizeArr);
        printf("Generated: ");
        for (int i = 0; i < sizeArr; ++i) {
            arr[i] = rand() % 10;
            printf("%d ", arr[i]);
        }

        printf("\n");
    
        if (write(fd[WRITE], &sizeArr, sizeof(int)) < 0) {
            printf("Error in write\n");
            return 2;
        }
        write(fd[WRITE], arr, sizeof(int) * sizeArr);
        
        close(fd[WRITE]);

    } else {
        // parent
        close(fd[WRITE]);
        
        int arr[10];
        int arrSize = 0, sum = 0;

        if(read(fd[READ], &arrSize, sizeof(int)) < 0) {
            printf("Error in read");
            return 3;
        }
        read(fd[READ], arr, sizeof(int) * arrSize);

        for(int i = 0; i < arrSize; ++i) {
            sum += arr[i];
        }
        printf("Sum is %d\n", sum);

        close(fd[READ]);
        wait(NULL);
    }

    return 0;
}
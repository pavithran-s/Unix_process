// write
#include <stdio.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>


int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int arr_size = sizeof(arr)/ sizeof(int);

    if (mkfifo("myfifo1", 0777) == -1) {
        if (errno != EEXIST){
            printf("Error in file creation\n");
        }
    }

    int fd = open("myfifo1", O_WRONLY);
    for(int i = 0; i < arr_size; ++i) {
        write(fd, &arr[i], sizeof(int));
        printf("Wrote number: %d\n", arr[i]);
    }
    close(fd);

    return 0;
}

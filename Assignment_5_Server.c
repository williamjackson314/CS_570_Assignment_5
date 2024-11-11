#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>


#define MAX_FILES 20
#define BLOCK_SIZE 512
#define FILE_SIZE 64    // Blocks
#define FILE_DISK_SIZE (FILE_SIZE * BLOCK_SIZE * MAX_FILES)

// Data structure for file info
typedef struct file_info {
    char* filename;
    int fd;
    char* username;
} file_info;

typedef struct file_table {
    file_info files[MAX_FILES];
    int num_files;
} file_table;

int main(){




    return 0;
}


// Function allocating space on linux virtual disk for the filetable
int create_disk(){
    int fd;

    fd = open("files.dat", O_RDWR|O_CREAT, 0666);
    if (fd == -1){
        printf("%s\n", strerror(errno));
        return -1;
    }
    else {
        if(ftruncate(fd, FILE_DISK_SIZE)){
            printf("%s\n", strerror(errno));
            return -1;
        }
    }

    return fd;
}

int open_file(char* filename, file_table file_table){
    if (file_table.num_files == MAX_FILES){
        printf("File table full.");
        return -1;
    }
    
    int fd = open(filename, O_RDWR);
    if (fd == -1){
        printf("%s\n", strerror(errno));
    }

    ftruncate(fd, FILE_SIZE * BLOCK_SIZE);

    file_table.files[file_table.num_files - 1]->filename = filename;
    file_table.files[file_table.num_files - 1].fd = fd;
    file_table.files[file_table.num_files - 1]->username = getpwuid(getuid())->pw_name;

    // Add check for space on files.dat

    
    return fd;
}

list_files(){

}
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
    char* f_ptr;
} file_info;

typedef struct directory {
    file_info usr_files[MAX_FILES];
    char* username;
    char* dir_ptr; // start of dir in disk
} directory;

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

file_info assign_directory(){
    directory usr_dir;
    usr_dir->dir_ptr = ;
    usr_dir->username = getpwuid(getuid())->pw_name;


    return usr_dir;
}

int open_file(char* filename){


}
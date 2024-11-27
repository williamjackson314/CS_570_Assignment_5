#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include "ssnfs.h"


#define MAX_FILES 20
#define BLOCK_SIZE 512
#define FILE_SIZE 64    // Blocks
#define FILE_DISK_SIZE (FILE_SIZE * BLOCK_SIZE * MAX_FILES)

// Data structure for file info
typedef struct file_info {
    char* filename;
    char* username;
    int fd;
} file_info;

typedef struct file_table {
    file_info files[MAX_FILES];
    int num_files;
} file_table;


int main(){




    return 0;
}


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

    //TODO: Add check for space on files.dat

    
    return fd;
}

int write_file(file_info usr_file, const void* buffer, int buf_size){

    int num_bytes = write(usr_file.fd, buffer, buf_size);
    if (num_bytes = -1){
        printf("%s", strerror(errno));
        return -1;
    }
    return num_bytes;
}


int read_file(file_info usr_file, void* buffer, int count){
    int num_bytes = read(usr_file.fd, buffer, count);
    if (num_bytes = -1){
        printf("%s", strerror(errno));
        return -1;
    }
    return num_bytes;

    //Make sure this is returning proper error if trying to read past the
    // end of le, le descriptor passed was not correct,
}

// TODO: Check that an int is compatible with lseek
void seek_position(file_info usr_file, int new_loc){
    lseek(usr_file.fd, new_loc, SEEK_CUR);
}

void list_files(char* username, file_table file_table){
    for (int i=0;i<file_table.num_files;i++){
        if (strcmp(file_table.files[i].username, username) == 0){
            printf("%s\n", file_table.files[i].filename);
        }
    }
}

void delete_file(file_info usr_file){
    int result = remove(usr_file.filename);
    if (result == -1){
        printf("%s", strerror(errno));
    }
}

void close_file(file_info usr_file){
    int result = close(usr_file.fd);
    if (result == -1){
        printf("%s", strerror(errno));
    }
}
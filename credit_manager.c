#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "error.h"
#define DATAFILE "player_details"
typedef struct{
    int userid;
    int credits;
} CREDITS;
typedef struct{
    CREDITS[];
}

int credit_manager(){
    int fd;
    int uid = getuid();
    fd = open(DATAFILE,O_RDWR|O_CREAT|O_APPEND,04600);
    if(fd == -1)
        fatal("in main while opening the file");
    

}

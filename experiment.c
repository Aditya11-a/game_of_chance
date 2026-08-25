#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "error.h"
#define FILENAME "credits_details"
typedef struct{
    int userid;
    int credits;
}CREDIT;

int main(){
    int fd , userid;
    userid = getuid();
    CREDIT cr;
    cr.userid = userid;
    cr.credits = 100;
    fd = open(FILENAME,O_RDWR|O_CREAT|O_APPEND,0600);
    if(fd == -1)
        fatal(" while opening the file\n");
    int a = write(fd,&cr,sizeof(CREDIT));
    if( a == -1)
        fatal("error while writing to the file\n");
    close(fd);
    printf("updated\n");
    return 0;
}
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
void idfinder(int,int,int);
void crupdater(int,int);
int main (int argc,char *argv[]){
int fd , userid;
int new_cr= atoi(argv[1]);
userid = getuid();
fd = open(FILENAME,O_RDWR);
if(fd == -1)
    fatal("error while opening the file");
idfinder(userid,new_cr,fd);
close(fd);
return 0;
}


void idfinder(int id, int creds,int fd){
    int a ;
    int *buffer = ec_malloc(sizeof(int));
    
    a = 4;
    while(a == 4){
        a = read(fd,buffer,4);
        if(a == -1)
        fatal("error wile reading the file");
        if(*buffer==id){
            crupdater(creds,fd);
            break;   
        }
        lseek(fd,4,SEEK_CUR);
        }
    printf("credits updated\n");
    free(buffer);
}

void crupdater(int creds, int fd){
    int a = write(fd,&creds,4);
    if(a== -1)
        fatal("while upadting credits");
    
}
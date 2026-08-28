#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "error.h"
#include "sturcts.h"
#define FILENAME "playe_info"


int suid(int,int);
PLAYER firsttime(int userid){  //if the user is logining for the first time create his profile else load his info. 
    int fd , wchecker, rchecker;
    PLAYER pinfo;
    fd = open(FILENAME,O_RDWR|O_CREAT|O_APPEND,0600);
    if(fd == -1)
        fatal("error while opening the file in firsttime");
    if(suid(userid,fd)){
        printf("welcome user %d ",userid);
        rchecker= read(fd,&pinfo.userid,sizeof(pinfo.userid));
        if(rchecker == -1)
            fatal("while loading player info");
        rchecker= read(fd,&pinfo.credits,sizeof(pinfo.credits));
        if(rchecker == -1)
            fatal("while loading playe info");
    }
    else{
        printf("welcome! user %d for the first time\n creating your profile\n",userid);
        pinfo.userid=userid;
        pinfo.credits=100;
        wchecker = write(fd,&pinfo,sizeof(pinfo));
        if(wchecker == -1)
            fatal("while creating user profile");
        printf("You have been given 100 credits use it wisely.\n");
        
    }
    if(close(fd) == -1)
        fatal("error while closing the file");
    return pinfo;
}

int suid(int id,int fd){
    int rchecker,rvholder;
    rchecker =4;
    while(rchecker == 4){
    rchecker = read(fd,&rvholder,sizeof(rvholder));
    if(rchecker == -1)
        fatal("error while searchig for folder");
    if (rvholder == id){
      lseek(fd,-4,SEEK_CUR);  
    return 1;
    }
    lseek(fd,4,SEEK_CUR);
    }
    return 0;
}


void idfinder(int id, int creds){ // it finds the user info and update the credits. 
    int a , fd;
    int *buffer = ec_malloc(sizeof(int));
    fd = open(FILENAME,O_RDWR);
    if (fd == -1)
        fatal("while openign the file to update");
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
    close(fd);
}

void crupdater(int creds, int fd){
    int a = write(fd,&creds,4);
    if(a== -1)
        fatal("while upadting credits");
    
}
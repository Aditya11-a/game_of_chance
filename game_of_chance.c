#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "error.h"
#include "sturcts.h"
#include "function.h"
#define FILENAME "player_info"




int main(){
    int logpid;
    logpid= getuid();
    firsttime(logpid);


    
}
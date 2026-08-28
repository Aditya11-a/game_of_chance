#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "sturcts.h"
#include "function.h"


PLAYER playerinfo;

int main(){
    int logpid, game = 0;
    logpid= getuid();
    playerinfo=firsttime(logpid);
    while(game !=4){
    printf("\n");
    printf("Your info:\n userid: %d \t credit balance: %d\n",playerinfo.userid,playerinfo.credits);
    printf("Choose the game you want to play:\n");
    printf("1: pick_a_number\n");
    printf("2: dealer_no_match\n");
    printf("3: find_the_ace\n Enter the index value of the game you want to play.\n press 4 exit");
    if(scanf("%d",&game)==0){
        while(getchar() != '\n');
        printf("enter a valid input");

    }
    else {
    if(game == 1){
        pick_a_number();
    }
    /*else if(game == 2){
        dealer_no_match();
    }
    else if(game == 3){
        find_the_ace();
    }*/
    else if(game == 4){
        idfinder(playerinfo.userid,playerinfo.credits);
    } 
    else
        printf("enter a valid index.");   
}
    }

return 0;    
}
#include <stdio.h>
#include <stdlib.h>
#include "sturcts.h"
#include "function.h"
#include <time.h>

void pick_a_number(){
    int  playerno, generatedno;
    char input;
    printf("You have to wager 10 credits in this game.\n");
    printf("You will choose a no. between 1 to 20 and then computer will give a random no.\n");
    printf("If they matches you will win 100 credits else you will loose 10 wagered credits.\n");
    printf("Press Y if you accept the terms and anything else to go back\n");
    input= getchar();
    getchar();
    if(input == 'Y' || input == 'y'){
        printf("enter your no.\n");
        scanf("%d",&playerno);
        srand(time(0));
        generatedno = rand()%20 +1;
        printf("computer generated no. %d\n",generatedno);
        if(generatedno == playerno){
            printf("You hit the jackpotpot!\n");
            playerinfo.credits += 100;
        }
        else{
            printf("You lost");
            playerinfo.credits -= 10;
        }
    }

}





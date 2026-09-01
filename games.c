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
    scanf(" %c",&input);
    printf("%c",input);
    if(input == 'Y' || input == 'y'){
        printf("enter your no.\n");
        scanf("%d",&playerno);
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


void dealer_no_match(){
    int wagered =0,i,j,duplicate_checker=0;
    int numbers[16];
    puts("Rules:");
    puts("You will choose a amount to wager.");
    puts("the dealer generates exactly 16 random numbers.Each no. should be between 0 and 99. All the nos. will be printed on the screen.");
    puts("If every single number is unique. You will win and your waged amount will be added to your total amount.");
    puts("If a single matching appears(duplicates) , you will lose and the amount will be deducted from your balance.");
    wagered = wager();
    if(wagered > 0){
        for(i=0;i<16 && duplicate_checker==0;i++){
            numbers[i]=rand()%100;
            printf("%d ",numbers[i]);
        }
        for(i=0;i<16;i++){
            for(j=i+1;j<16;j++){
                if(numbers[i] == numbers[j]){
                    duplicate_checker =1;
                    break;
                }

            }
        }
        if(duplicate_checker == 1){
        puts("You lost! There are duplicate numbers");
        playerinfo.credits -= wagered;
        }
        else{
            playerinfo.credits += wagered;
            printf("You won . %d added to your credit balance.\n",wagered);
        }
    }
    else if(wagered == -1){
        ;
    }
    
}

void find_the_ace(){
    int wagered = 0,ace_position,i,d,replay=-1;
    int guess=-1;
    char position[4];
    for(i=0;i<4;i++){
        position[i]='X';
        if(i==3)
            position[i]=0; 
    }
    puts("The Dealer will shuffle three cards. 1 ACE and 2 QUEENS.");
    puts("You have to guesse what is the position of ACE.");
    puts("If you guess right you win and your wagered amount will added to your credit balance.");
    puts("If you lost your wagered amount will be subtracted from your balance.");
    wagered = wager();
    if(wagered != -1){
        while(replay !=0){
        for(i=0;i<4;i++){
        position[i]='X';
        if(i==3)
            position[i]=0; 
    }
        replay =-1;
        guess = -1;
        for(i=0;i<3;i++){
            printf("[%c]\t",position[i]);
        }
        putchar('\n');
        puts("Guesse the position of ACE");
        while(guess <=0 || guess>=4){
        if((d=scanf(" %d",&guess))==0){
            while(getchar()!= '\n');
            puts("enter valid input");
            continue;
        }
        else if(guess <=0 || guess>=4)
            puts("enter a valid no.");
    }
        ace_position=rand()%3;
        for(i=0;i<3;i++){
            if(i == ace_position)
                position[i]='A';
            else
                position[i]='Q';
            printf("[%c]\t",position[i]);
        }
        putchar('\n');
        if((guess-1)==ace_position){
             puts("You win.");
             playerinfo.credits += wagered;
        }
        else{
            puts("You lost.");
            playerinfo.credits -= wagered;
        }
        putchar('\n');
        puts("Do you want to play again with double wager. 1 to play 0 to exit.");
        while(replay>1 || replay <0){
            if(scanf(" %d",&replay)!=1){
            while(getchar()!= '\n');
        }
    }
    if(replay==1){
        if((wagered<<1)>playerinfo.credits)
            puts("You don't have much credit to wager");
        else
            wagered<<=1;
        }
    }
    
}
else
        ;

}

int wager(){
    int wager = 0;
    while(wager != -1){
    printf("Enter the no. of credits you want to wager or -1 to go back.\n Wager should  belong to (0,your credits]\n");
    if(scanf(" %d",&wager) == 0){
        while(getchar() != '\n'){
            ;
        }
    printf("Enter a valid amount.\n");
    continue;
    }

    if(wager > 0 && wager<= playerinfo.credits)
        return wager;
    else if(wager == -1)
        return -1;
    else
        printf("Enter a valid amount.\n");
}

}





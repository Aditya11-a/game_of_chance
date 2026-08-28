#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#define FILENAME "player_info"
typedef struct{
    int userid;
    int credits;
}Player;
int main(){
    Player player0;
    player0.userid = getuid();
    printf("Welcome! User %d\n",player0.userid);
    if(firsttime(player0.userid))

    
}
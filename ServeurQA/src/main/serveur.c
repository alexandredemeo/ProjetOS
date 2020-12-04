#include <stdio.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h> 
#include <errno.h>
#include <string.h>

int main(int argc, char * argv[]){
    int p1 = 0;
    char tmp[200];
    int pidclient;
    int dp, f;
    char buf;
    char controld[200]="control+D";
    unlink("pipe");
    mkfifo("pipe" ,0666);


    p1 = fork();

if(p1==0)
{   
pidclient=getpid();
}
   if(p1 != 0){
        system("clear");
        dp=open("pipe",O_RDONLY);
        printf("-----------------------SERVEUR------------------------");
        read(dp,tmp,200);
       printf("%s",controld);
       while(strcmp(controld,tmp)!=0)
       {

        printf("le client ecrit:\n");
        printf("%s\n",tmp);

       }
        kill(p1,SIGKILL); 
        execv("fermerterm.sh",NULL);
        close(dp);
    }
    else{
        execv("client.sh",NULL);
    }
printf("le programme continu\n");
   return 0;
}

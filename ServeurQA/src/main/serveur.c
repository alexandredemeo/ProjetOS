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
    int tmp = 25310;
    int dp, f;
    char com[200];
    char oldcom[200];
    int pidclient;
    char ctrld[2]="cd";
    char* SHELL;
    SHELL=getenv("SHELL");    

    unlink("pipe");
    mkfifo("pipe" ,0666);


    p1 = fork();
    if(p1 != 0){

        dp=open("pipe",O_RDONLY);
        read(dp, &tmp,sizeof(int));
        printf("------SERVEUR---------\n");
        printf("le pid du client est %d \n", tmp);
        pidclient=tmp;
        while(strcmp(com,ctrld)!=0)
        {
          com[1]='\0';
          read(dp,com,200*sizeof(char));
          printf("Le client a ecrit :\n %s\n", com);

 
        }
        kill(pidclient,SIGKILL);
        close(dp);
    }
    else{
        //execv("client.sh",NULL);
        execl("/usr/bin/xterm","xterm","-e","./client",NULL);
    }

    return 0;
}

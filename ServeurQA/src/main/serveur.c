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

int main(){

int p1 = 0;
int dp;
int pidclient;
char com[200]="";
char oldcom[200];
char ctrld[10]="ctrld";
unlink("pipe");
mkfifo("pipe" ,0666);

p1 = fork();



if(p1 != 0){

printf("---------SERVEUR---------\n");

while(1){

for(int i=0;i<200;i++){
com[i]='\0';
}

dp=open("pipe",O_RDONLY);
read(dp, &pidclient,sizeof(int));
printf("le pid du client est %d \n", pidclient);

while(strcmp(com,ctrld)!=0){

for(int i=0;i<200;i++){
com[i]='\0';
}

read(dp,com,200*sizeof(char));
printf("Le client a ecrit :\n %s\n", com);

}

close(dp);

}



}
else{

execl("/usr/bin/xterm","xterm","-e","./client","pipe",NULL);
}

return 0;

}

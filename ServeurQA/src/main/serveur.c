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

void fork_it(int n)
{
int i;
pid_t f=1;

for(i=1;i<n && f>0;i++)
{
  f=fork();
}

  execl("/usr/bin/xterm","xterm","-e","./client","pipe",NULL);

}
int main(int argc, char * argv[]){

int p1 = 0;
int dp;
int pidclient;
char com[200]="";
char oldcom[200];
char ctrld[10]="ctrld";
unlink("pipe");
mkfifo("pipe" ,0666);
int nb_clients=atoi(argv[1]);
p1 = fork();



if(p1 != 0){

printf("---------SERVEUR---------\n");

while(1){

for(int i=0;i<200;i++){
com[i]='\0';
}

dp=open(argv[2],O_RDONLY);
//read(dp, &pidclient,sizeof(int));
//printf("le pid du client est %d \n", pidclient);

while(strcmp(com,ctrld)!=0){

for(int i=0;i<200;i++){
com[i]='\0';
}

read(dp, &pidclient,sizeof(int));
read(dp,com,200*sizeof(char));
printf("Le client %d a ecrit :\n %s\n",pidclient, com);

}

close(dp);

}



}
else{
fork_it(nb_clients);
//execl("/usr/bin/xterm","xterm","-e","./client","pipe",NULL);
}

return 0;

}

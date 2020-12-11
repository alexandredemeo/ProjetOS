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

int i=1;

int main(void){

int des;
char line;
int buf=getpid();
char com[200]="\0";
char ctrld[10]="ctrld";

des=open("pipe",O_WRONLY);
write(des,&buf,sizeof(int));
    sleep(2);

printf("voici mon pid : %d\n", buf);

while(i!=0){

printf("Saisir la commande a envoyer au serveur :");

if(fgets(com, 200, stdin)==NULL){
i=0;
}else{
write(des,com,(strlen(com)*sizeof(char)));
}
}
write(des,ctrld,strlen(ctrld)*sizeof(char));
close(des);
exit(0);
return 0;
}

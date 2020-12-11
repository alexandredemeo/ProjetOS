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
    char com[200]="";
    char ctrld[2]="cd";
    des=open("pipe",O_WRONLY);
    write(des,&buf,sizeof(int));
    sleep(2);
    printf("voici mon pid : %d\n", buf);

while(i!=0){
    printf("Saisir la commande a envoyer au serveur :");
//    line=fgets(com, 200, stdin);
  com[0]='\0';
  if(fgets(com, 200, stdin)==NULL)
  {
    i=0;
    

  }else
    {
     write(des,com,(strlen(com+1)*sizeof(char)));
    }
}

    close(des);
    exit(0);
    return 0;
}

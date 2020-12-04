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
int main(void){
    int des;
    int buf;
    int i=0;
    int lu;
    char buffer[200];
    char controld[200]="control+D";
 
for(;;){ 
    printf("entrer votre commande\n");
    fgets(buffer,200,stdin);

    des=open("pipe",O_WRONLY);
    //write(des,&buf,sizeof(int));

     write(des, buffer,(strlen(buffer+1)*sizeof(char)));

    close(des);
}
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <time.h>

int sockfd = 0,acceptfd = 0;
char data[1024];
struct sockaddr_in serv_env;
time_t ticks;
int main(int argc,char *argv[]){

// creating socket
sockfd = socket(AF_INET,SOCK_STREAM,0);
if (sockfd < 0) {
   /* code here */ 
   perror("Error:");
   exit(1);
}else {
   /* code here */ 
   puts("----------Socket created --------");
}

// set memmory locations values
memset(&serv_env,'0',sizeof(serv_env));
memset(data,'0',sizeof(data));

// establish server port and address
serv_env.sin_family = AF_INET;
serv_env.sin_port = htons(5000);
serv_env.sin_addr.s_addr = htonl(INADDR_ANY);
// binding the connection
bind(sockfd,(struct sockaddr*)&serv_env,sizeof(serv_env));

// listening to the clients
int lisen = listen(sockfd,10);// listening to 10 clients maximum
if (lisen < 0) {
   /* code here */ 
   perror("listen() failed:");
   exit(1);
} else {
   /* code here */ 
   puts("*********Handshake sucessfull*******");
}
while (1) {// Infinite loop to keep the server running
   /* code here */ 
   ticks = time(NULL);

    acceptfd = accept(sockfd,(struct sockaddr*)NULL,NULL);
    snprintf(data,sizeof(data),"%.24s\r\n",ctime(&ticks));// storing the time in the data variable.

    write(acceptfd,data,sizeof(data));
    close(acceptfd);
puts("Running.......");
    sleep(2);// Sleep the server for 2 seconds to prevent it from over use the CPU processing.
}
return 0;
}
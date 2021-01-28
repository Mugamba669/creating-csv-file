#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

    int sockfd = 0;
    int connfd = 0;
    int code,n =0;
    char buffer[100];
    struct sockaddr_in server;

int main(int argc,char *argv[]){
   
if (argc != 2) {
   /* code here */ 
   printf("\nUsage :%s <ip of server>\n",argv[0]);
  // return 1;
}
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    if (sockfd < 0) {
       /* code here */ 
       perror("Socket() failed:");
       exit(1);
    }else {
       /* code here */ 
       puts("*******Socket has been successfully created*****");
    }
    // Establishing the server address
    server.sin_family = AF_INET; // using Ipv4
    server.sin_port = htons(5000); // server running on port 5000
    // Establish server connection
    connfd = connect(sockfd,(struct sockaddr *)&server,sizeof(server));
    // checking for connectivity....
    if (connfd < 0) {
       /* code here */ 
       perror("connect() faiiled:");
       exit(1);
    } else {
       /* code here */ 
       puts("=========Successfully connected to the server==========");
    }
// conversion to in_addr()
    if (inet_pton(AF_INET,argv[1],&server.sin_addr) <= 0) {
       /* code here */ 
       perror("Error: conversion failed");
       exit(1);
    }
    // 
    memset(&server,'0',sizeof(server));// allocate memmory for the server
    memset(buffer,'0',sizeof(buffer));// allocate memory to output variable
    // reading data from the server
    n = read(sockfd,buffer,sizeof(buffer)-1);
    while (n > 0) {
       /* code here */ 
        
        buffer[n] = 0;
        if (fputs(buffer,stdout) == EOF) {
           /* code here */ 
           puts("Error:fputs error");
        }

        //close(n);
    }
    if (n < 0) {
       /* code here */ 
       perror("Error: read() failed.");
       exit(1);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
#define PORT 4444
#define BUF_SIZE 2000
#define CLADDR_LEN 100

void main() {
 struct sockaddr_in addr, cl_addr;
 int sockfd, len, ret, newsockfd;
 char buffer[BUF_SIZE],buff[BUF_SIZE];
 char clientAddr[CLADDR_LEN];
 int temperature,humidity,methane,propane,carbonmonoxide;
 time_t s, val = 1;
 struct tm* current_time;
 FILE *fptr;
 sockfd = socket(AF_INET, SOCK_STREAM, 0);
 //printf("socket fd is: %d",sockfd);
 if (sockfd < 0) {
  printf("Error creating socket!\n");
  exit(1);
 }
 //printf("Socket created...\n");
 
 memset(&addr, 0, sizeof(addr));
 addr.sin_family = AF_INET;
 addr.sin_addr.s_addr = INADDR_ANY;
 addr.sin_port = PORT;
 
 ret = bind(sockfd, (struct sockaddr *) &addr, sizeof(addr));
 if (ret < 0) {
  printf("Error binding!\n");
  exit(1);
 }
 printf("Binding done...\n");

 //printf("Waiting for a connection...\n");
 listen(sockfd, 1);

 for (;;) { //infinite loop
  len = sizeof(cl_addr);
  newsockfd = accept(sockfd, (struct sockaddr *) &cl_addr, &len);
  if (newsockfd < 0) {
   printf("Error accepting connection!\n");
   exit(1);
  }
  //printf("Connection accepted...\n");
  inet_ntop(AF_INET, &(cl_addr.sin_addr), clientAddr, CLADDR_LEN);
   for (;;) {
    memset(buffer, 0, BUF_SIZE);
    s=time(NULL);
    ret = recvfrom(newsockfd, buffer, BUF_SIZE, 0, (struct sockaddr *) &cl_addr, &len);
    if(ret < 0) {
     printf("Error receiving data!\n");  
     exit(1);
    }
    //printf("Received data from client is: %s\n",buffer);
    //added
    if(strcmp(buffer,"Getdata")==0)
    {
      fptr = fopen("sensor1.txt", "r");
      if (fptr == NULL)
      {
       printf("Can't open file for reading.\n");
      }
      else
      {
       fscanf(fptr, "%d", &temperature);
       fclose(fptr);
      }
      //printf("temperature : %d",temperature);
      fptr = fopen("sensor2.txt", "r");
      if (fptr == NULL)
      {
       printf("Can't open file for reading.\n");
      }
      else
      {
       fscanf(fptr, "%d", &humidity);
       fclose(fptr);
      }
      //printf("humidity : %d",humidity);
      fptr = fopen("sensor3.txt", "r");
      if (fptr == NULL)
      {
       printf("Can't open file for reading.\n");
      }
      else
     {
      fscanf(fptr, "%d", &methane);
      fclose(fptr);
     }
      //printf("methane : %d",methane);
      fptr = fopen("sensor4.txt", "r");
      if (fptr == NULL)
      {
       printf("Can't open file for reading.\n");
      }
      else
      {
       fscanf(fptr, "%d", &carbonmonoxide);
       fclose(fptr);
      }
      //printf("carbonmonoxide : %d",carbonmonoxide);
      fptr = fopen("sensor5.txt", "r");
      if (fptr == NULL)
      {
       printf("Can't open file for reading.\n");
      }
      else
      {
      fscanf(fptr, "%d", &propane);
      fclose(fptr);
      }
       //printf("propane : %d",propane);
       current_time = localtime(&s);
       sprintf(buff,"%02d:%02d:%02d,%d,%d,%d,%d,%d",current_time->tm_hour,current_time->tm_min,current_time->tm_sec,temperature,humidity,methane,carbonmonoxide,propane);
       //printf("Data sent to client is:%s\n",buff);
       ret = sendto(newsockfd, buff, BUF_SIZE, 0, (struct sockaddr *) &cl_addr, len);   
       if (ret < 0) {  
       printf("Error sending data!\n");  
       exit(1);     
    }            
    
   }
  }
  close(newsockfd);
 }
}


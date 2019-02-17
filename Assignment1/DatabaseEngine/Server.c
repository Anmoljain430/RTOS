// C Program for Message Queue (Server) 
#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <string.h>
// structure for message_send queue 
struct msg_buffer { 
	long msg_type; 
	char msg_text[100]; 
} message_send,message_rcv; 

int main() 
{ 
	key_t key[2]; 
	int msgid_send,msgid_rcv,i;
        char ch;	
	// ftok to generate unique key 
	key[0] = ftok("/tmp",'S');
        key[1] = ftok("/tmp",'R');

	// msgget creates a message_send queue 
	// and returns identifier 
	msgid_send = msgget(key[1], 0666 | IPC_CREAT); 
        msgid_rcv = msgget(key[0], 0666 | IPC_CREAT);
	char filename[20];
	// msgrcv to receive message_send 
        while(1)
        {		
	 for (i=2;i<7;i++)
          {
                int temp;
		if (temp=msgrcv(msgid_rcv, &message_rcv, sizeof(message_rcv), i, IPC_NOWAIT)==-1)
		{       	
                   //printf("No inputs");
		   continue;
		} 
	        // display the message_send 
	        //printf("client%d",i);

		printf("String received from client%d is : %s \n",i,message_rcv.msg_text);
                //added here
		
		FILE *fptr;
                char c;
                //fptr = fopen(message_rcv.msg_text, "r");
		char temp1[3];
                temp1[0] = i+'0';
                temp1[1] = '/';
		temp1[2]= '\0';
		strcpy(filename,"./Client");
		strcat(filename,temp1);
		strcat(filename,message_rcv.msg_text);
		fptr = fopen(filename,"r");
                if (fptr == NULL)
                {
	          strcpy(message_send.msg_text,"File Not Found");
                }
                else
		{	
                   c = fgetc(fptr);
                   message_send.msg_text[0] = c;
                   int j=1;
                   while (c != EOF)
                   {
                      // printf ("%c", c);
                      c = fgetc(fptr);
                      message_send.msg_text[j]=c;
                      j++;
                   }
                   message_send.msg_text[j-1]='\0';
                   fclose(fptr);
                 }
		 printf("String Sent to client%d is :\n%s\n",i,message_send.msg_text);
                 message_send.msg_type=i;
                 msgsnd(msgid_send,&message_send, sizeof(message_send), i); 	
	  }
        }
	// to destroy the message_send queue 
	//msgctl(msgid, IPC_RMID, NULL); 

	return 0; 
} 


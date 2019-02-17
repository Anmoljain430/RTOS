// C Program for Message Queue (Server) 
#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <string.h>
// structure for message_send queue 
struct msg_buffer { 
	long msg_type; 
	char msg_text; 
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
		ch = message_rcv.msg_text;
		printf("Character received from client%d is : %c \n",i,message_rcv.msg_text);
                if(ch >= 'A' && ch <= 'Z')
                {
                  message_rcv.msg_text = ch -'A'+'a'; 
                }
                else if(ch >= 'a' && ch <= 'z')
                {
                 message_rcv.msg_text = ch-32;
                }
		printf("Character Sent to client%d is : %c \n",i,message_rcv.msg_text);

                msgsnd(msgid_send,&message_rcv, sizeof(message_rcv), i); 	
	  }
        }
	// to destroy the message_send queue 
	//msgctl(msgid, IPC_RMID, NULL); 

	return 0; 
} 


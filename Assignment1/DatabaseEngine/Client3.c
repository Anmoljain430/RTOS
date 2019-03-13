// C Program for Message Queue (Writer Process) 
#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 

// structure for message_send queue 
struct msg_buffer { 
	long msg_type; 
	char msg_text[100]; 
} message_send,message_rcv; 

int main() 
{ 
	key_t key[2]; 
	int msgid_send,msgid_rcv; 

	// ftok to generate unique key 
	key[0] = ftok("/tmp",'S'); 
        key[1] = ftok("/tmp",'R');
	// msgget creates a message_send queue 
	// and returns identifier 
	msgid_send = msgget(key[0], 0666 | IPC_CREAT);
        msgid_rcv = msgget(key[1],0666 | IPC_CREAT);	
       // User2 message_send
        message_send.msg_type = 3;
	while(1)
        {		
          printf("Enter filename for client3 or ctrl+c to exit :\n");
          //gets(message_send.msg_text);
	  scanf("%[^\n]%*c",message_send.msg_text);
          // msgsnd to send message_send
          msgsnd(msgid_send, &message_send, sizeof(message_send), 3);

          // display the message_send
          printf("Filename sent from client3 is : %s \n", message_send.msg_text);
	  msgrcv(msgid_rcv, &message_rcv, sizeof(message_rcv), 3, 0);
	  int temp;
	  /* 
	  if (temp=msgrcv(msgid_rcv, &message_rcv, sizeof(message_rcv), 2, 0)==-1);
          {
	   //printf("getchar invoked");
	   //getchar();	     
          }*/
	  printf("Details received from Server is :\n%s\n", message_rcv.msg_text);
	}
	return 0; 
} 


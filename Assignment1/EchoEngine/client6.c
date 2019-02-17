// C Program for Message Queue (Writer Process) 
#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 

// structure for message_send queue 
struct msg_buffer { 
	long msg_type; 
	char msg_text; 
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
        message_send.msg_type = 6;
        // doubt of 2 times iterations
	while(1)
        {		
          printf("Enter a single character for client6 or ctrl+c to exit :\n");
	  message_send.msg_text = getchar(); 
          //gets(message_send.msg_text);
          // msgsnd to send message_send
          msgsnd(msgid_send, &message_send, sizeof(message_send), 6);

          // display the message_send
          printf("Character sent from client6  is : %c \n", message_send.msg_text);
	  int temp; 
	  if (temp=msgrcv(msgid_rcv, &message_rcv, sizeof(message_rcv), 6, 0)==-1);
          {
	   getchar();	     
          }
	  printf("Character received from server is : %c\n", message_rcv.msg_text);
	}
	return 0; 
} 


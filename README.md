# RTOS
This assignment is implementing a single server and multi client system using message queues.

Problem1:

In this problem the server and clients will be running simulaneously and exchanging data through 2 message queues.

Description:
              There is a single server and 5 clients from client2 to client6.

Functionality:

1. User needs to enter the character at client side.
2.The server will convert a lowercase character to uppercase & also vice-versa.
3.If its not an alphabetic character it will send the character as it is.

Execution steps:
1.Run each client and server in different terminals.
2.Enter a single character at the client.
3.The Server will send back the character based on above functionality.

Problem2:

Description:

There is a single server and 5 clients from client2 to client6.

1.Create 5 directories client2,client3....client6.Under each subdirectory create 2 files " Details.txt  Grade.txt "

Functionality:
1.All the 5  clients and  Server will be running in different terminals.

2.User enters the filename at the client end.The client will send the filename to server through message queue.The Server will fetch the data from the file and sends it to client through another queue.

Execution steps:

1.Create 5 directories and files as in the description.

2.All the 5  clients and  Server should be running in different terminals.

2.Enter the filename at the client side.The Server will send the data from the file if the file exists.It will throw a message as "File Not Found" if file not present at server side.




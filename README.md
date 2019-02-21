# **RTOS**
This assignment is implementing a single server and multi client system using message queues.

**Problem1:**

In this problem the server and clients will be running simulaneously and exchanging data through 2 message queues.

**Description:**

              There is a single server and 5 clients from client2 to client6.

**Functionality:**

1. User needs to enter the character at client side.

2.The server will convert a lowercase character to uppercase & also vice-versa.

3.If its not an alphabetic character it will send the character as it is.

**Execution steps:**

1.Run each client and server in different terminals.

2.Enter a single character at the client.

3.The Server will send back the character based on above functionality.

**Problem2:**

**Description:**

There is a single server and 5 clients from client2 to client6.

1.Create 5 directories client2,client3....client6.Under each subdirectory create 2 files " Details.txt  Grade.txt "

**Functionality:**

1.All the 5  clients and  Server will be running in different terminals.

2.User enters the filename at the client end.The client will send the filename to server through message queue.The Server will fetch the data from the file and sends it to client through another queue.

**Execution steps:**

1.Create 5 directories and files as in the description.

2.All the 5  clients and  Server should be running in different terminals.

2.Enter the filename at the client side.The Server will send the data from the file if the file exists.It will throw a message as "File Not Found" if file not present at server side.

**Performance Data**

**1.Echo engine**

 Time taken (ms)
 
|S.No:| 1 client | 2 clients | 3 clients | 5 clients | 
| --- | ---     |---|---|---|
| 1 | 1.639 | 1.879 | 1.889 | 2.958
| 2 | 1.342 | 1.646 | 2.259 | 2.847
| 3 | 1.390 | 1.563 | 3.173 | 3.362
| 4 | 1.297 | 1.978 | 2.890 | 3.353
| 5 | 1.425 | 1.371 | 2.326 | 2.678

**Inferences:**

   From the above table time taken increases as number of clients increases.
   
   Average time variation (min.time - max.time)
   
   For 1 client average time taken is around 1.5ms  (1.29 - 1.65)
   For 2 clients average time taken is around 1.8ms (1.37 - 1.98)
   For 3 clients average time taken is around 2.2ms (1.88 - 2.89)
   For 5 clients average time taken is around 2.9ms (2.67 - 3.36)
   
**2.Database Engine**
   
Time taken (ms)

|S.No:| 1 client | 2 clients | 3 clients | 5 clients | 
| --- | ---     |---|---|---|
| 1 | 1.219 | 1.424 | 1.721 | 3.550
| 2 | 1.189 | 1.314 | 2.492 | 5.131
| 3 | 1.211 | 1.500 | 1.851 | 2.624
| 4 | 1.169 | 1.828 | 2.383 | 2.814

**Inferences**

From the above table time taken increases as number of clients increases.The average time increases with variation in min.time & max. time as in the table

   
            

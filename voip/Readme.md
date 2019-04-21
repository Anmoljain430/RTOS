**Description:**

In this assignment a Voice over ip is implemented through socket programming.I have used 2 sockets one for send and the other for receive.

**Functionality:**

1.I have taken 2 Systems for implementation, so at each system there will be a server and a client running in 2 tabs or terminals.
  
2.The Server will be receiving the continous recorded audio file and playback using the "pa_simple_write" API.
 
3.The client will be recording the audio continously and send it to the server through socket programming.
 
**Execution steps:**

1.Take 2 different machines System1 (172.16.132.59) & System2 (172.16.132.69)  -- these were my ips in the test.

2.Copy Server1.c and client.c in system1 (172.16.132.59)  --let us say

3.Run Server1.c and client.c as follows :

  **cc client.c -o client -lpulse -lpulse-simple**
  **cc Server1.c -o server1 -lpulse -lpulse-simple**

4.Perform the above 2 steps in system2 (172.16.132.69) i.e copy client1.c and Server.c and compile it. 
 
  **cc client1.c -o client1 -lpulse -lpulse-simple**
  **cc Server.c -o server -lpulse -lpulse-simple**

5.Run the server1 and server (binary files) in the 2 systems first as to establish sockets.

6.Now run both the client files in the respective systems as follows:

  ./client1 172.16.132.59 -- in system2
  
  Similarly,
  
  ./client 172.16.132.69 -- in system1
  
  **Note:Operator has to enter the ip address otherwise it will throw segmentation fault error and exits.**
  
7.Now the operator has to connect an headset at both the systems & 2 way voip can be performed. 
  
 **Writeup:**
 
 1.Initially tried recording to a file by tweaking the sample program "parec-simple.c" and was successful in writing it to a file.
 
 2.Gave this recorded file as command line argument to the other program "pacat-simple.c" and it played back with small noise.
 
 3.Integrated the above functionality to a single socket,sending the file as data through buffer and playing it at server.
   There occured some issues with regarding to buffer as the audio file contained encoded characters not an ascii one.
 
 4.So,modified these buffers and also adusted size of buffer so that the audio is played properly.
 
 5.After completing the above subpart integrated the whole pulseaudio to the client and server so that the data gets streamed directly 
   without having to write to file and tweaked a bit by adding sleep statements so as to have better performance.
   
 6.Noise is one of the critical things to deal with.In the initial stage the noise gets ampified while playing without headset with decaying
   echo of the sent audio signal strength.
 
 7.Using headset will decrease the noise signal strength through filters to predefined level and the noise got decreased.Tweaked some 
   more pulseaudio paramters like "signal rate".On decreasing the signal rate by some multiples elongated the audio which got added 
   with noise and unable to hear it.
 
 8.Used the sample rate mentioned 44100 and tweaked some paramters in volume but didn't find significant change in them so kept them as
   default.
 
 9.One of the task which i wanted to improve is sending only the recorded audio through  relative signal strength of the recorded audio
   as while hearing through the headset the noise is minute with uniform small signal strength but couldn't reduce further the noise 
   through volume control
   .
   
 

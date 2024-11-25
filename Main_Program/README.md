# CS_570_Assignment_5
Implement a stateful server using Sun RPC protocol


**Unfinished**
* Read works for stateless server
* Write works for stateless server




**Finished**



**General Questions/Concerns**
* What does assigning a directory to each user entail?
* How do I have the server only using the virtual disk memory from linux file?
* In seek_file, how is the location specified? Is it an offset?
* How do I return an error to the client?
* How do I run both the client and server on the same machine?
* What val should I write to the 'success' field for the various types?
* How do I specify what port/ip to run the server at in the client?
* How do I initialize the file table?



**Assumptions**
* Just going to implement user directory as a list of file descriptors assigned to each user 
* Assume seek_position uses an offset as a specifier
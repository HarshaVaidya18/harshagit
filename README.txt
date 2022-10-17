*********************************task1********************************
1)Here we use exec family of calls to chang the image of the process.
2)When we run ./a.out command the image is changed to the desired image.

*********************************task2********************************
1)In this code we create two threads and use mutex locks to achieve synchronization among both the threads.
2)So when the thread execution begins, All the prints are printed in a synchronized way. i.e., for each print, The control of execution is handed to other thread.
3)Each thread prints a number and hands over the control to the other thread until both the threads are done with execution. 

*********************************task3********************************
1)In this code, we implement our own kill command.
2)kill command can be implemented by passing the pid of a process and the signal number that we want to send to the process.
3)Here the arguments are passed through command line arguments.
4)In the code, we convert the arguments from ASCII to int, since the command line arguments are of type char* .
5)Then we use the kill() function and pass both the arguments which are converted atoi(). 
6)when we run the program with the signal no and pid of a process as the command line arguments, the kill command is implemented.

*********************************task4********************************
1)In this program, We create two threads to print the capitl letters and small letters present in a string.
2)Here we take a string as an input from the user and pass it as an argument to two threads.
3)One thread prints all the small letters that are present in the string.
4)the other thread prints all the capital letters that are present in the string.

*********************************task5********************************
1)Task1
*********************************task6********************************
1)In this program we create and remove a directory through the code without using the command.
2)For that, we use the functions mkdir() to create a directory in run-time and rmdir() to remove a directory.

*********************************task7********************************

*********************************task8********************************
1)In this code, we create a file in runtime without using creat.
2)For this, we use fopen() function. This function internally creates the file and opens it in the mode which is specified.

*********************************task9********************************
1)In this program, we need to list the contents of the directory.
2)For that, we used the system call opendir(). 
3)This function opens the desired directory and returns the pointer that holds the information present in the directory which is of type struct dirent * .4)Then we run a loop by reading the content of the file by using the function readdir().
5)This loop runs until it reaches the end of the directory and prints the file/directory present in the directory.
 
********************************task10********************************
1)In this program, We need to change the behaviour of the signal.
2)For this we write our own myhandler() function and pass it as an argument to the signal() function.
3)When we specify the signal number in the signal function, the behaviour of that particular function is changed and the myhandler() function gets executed everytime the process receives that particular signal.

*********************************task11********************************
1)In this program, We have to swap the content of two files.
2)We pass both the files as inpud through command line arguments.
3)For this, First we open both the files and read all the data present in the file and store it in different buffers.
4)Then we remove all the data present in the file by using the ftruncate() function.
5)Then we write the data of the other file into the other files which are stored in the buffers.
6)Finally the data are swapped between both the files.

*********************************task12********************************
1)In this program we have to print even and odd numbers from two different threads but without using mutex.
2)Without any synchronization machanism like mutex, here we just use a blocking call like sleep().
3)In this case, The threads goes into blocking state after printing a number and hands over the execution to the other thread and vic versa. 
4)The numbers are printed from the two threads alternatively.

*********************************task13*******************************
1)In this program, we need to send a message from parent process to child process.
2)For this, here we are using the pipe() IPC mechanism.
3)Pipes are used to send data between two related processes.
4)pipe() returns 2 fd's. One is the read fd and the other is write fd.
5)In parent process we close the read fd and write into a buffer and send a message to child using write fd.
5)Similarly, In chid process, we close the write fd and and read the data that is send from the parent using the read fd.

*********************************task14********************************
1)In this program, We establish communication between two processes using shared memory.
2)Here, one process creates a shared memory in the user space of RAM and attaches itself to the shared memory.
3)The other process directly attaches itself to the shared memory using shmat().
4)This shared memory is identified by a unique key which is unique for each shared memory.
5)Once the processes attaches itself to the shared memory, They can place their message in the shared memory and the other process can read the data from that shared memory.
6)But, This method of IPC has no synchronization.
*********************************task15********************************
1)In this program, We use semaphore sets, which is a synchronization mechanism.
2)Semaphore is a counter which is accessed by multiple processes and perform operations using this semaphore counter.
3)When a process writes a message into a shared memory/message queue, That process increments the semaphore counter value by 1.
4)When the other process reads the data from that shared memory/message queue, That process decrements the semaphore counter value by 1.
5)In this way, We can achieve synchronization between processes.

*********************************task16********************************
1)In this program, We establish communication between two process using message queues.
2)Message queues are nothing but queues of messages qhich are maintained by kernel.
3)These messages are placed in queue by a process and other process can access the message directly from the message queue.


*********************************task17********************************
1)In this program, We print even numbers in one thread and odd numbers in one thread using conditional variables.
2)Conditional variables are also synchronization mechanism just like mutex variables.
3)When a thread locks a mutex variable and conditional variable, it stays in locked position until other process sends a signal, i.e., when the other thread uses pthread_cond_signal() call.
4)Then the other threads gets awaken and continues its execution.

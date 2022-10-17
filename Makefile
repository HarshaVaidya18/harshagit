#a.out : 1exec.o 2mutex.o 3mykill.o 4capsmall.o 6directory.o 8createfile.o 9ls.o 10sigbehaviour.o 11swapfiles.o 13pipes.o 17condvariable.o 

1exec : 1exec.c
	gcc -o 1exec 1exec.c
2mutex : 2mutex.c
	gcc  -o 2mutex 2mutex.c -lpthread
3mykill : 3mykill.c
	gcc -o 3mykill 3mykill.c
4capsmall : 4capsmall.c
	gcc -o 4capsmall 4capsmall.c
6directory : 6directory.c
	gcc -o 6directory 6directory.c
8createfile : 8createfile.c
	gcc -o 8createfile 8createfile.c
9ls : 9ls.c
	gcc -o 9ls 9ls.c
10sigbehaviour : 10sigbehaviour.c
	gcc -o 10sigbehaviour 10sigbehaviour.c
11swapfiles : 11swapfiles.c
	gcc -o 11swapfiles 11swapfiles.c
12evenodd : 12evenodd.c
	gcc -o 12evenodd 12evenodd.c
13pipes : 13pipes.c
	gcc -o 13pipes 13pipes.c
14shmserver : 14shmserver.c
	gcc -o 14shmserver 14shmserver.c
14shmclient : 14shmclient.c
	gcc -o 14shmclient 14shmclient.c
15semaphoreserver : 15semaphoreserver.c
	gcc -o 15semaphoreserver 15semaphoreserver.c
15semaphoreclient : 15semaphoreclient.c
	gcc -o 15semaphoreclient 15semaphoreclient.c
16msgqserver : 16msgqserver.c
	gcc -o 16msgqserver 16msgqserver.c
16msgqclient : 16msgqclient.c
	gcc -o 16msgqclient 16msgqclient.c
17condvariable : 17condvariable.c
	gcc -o 17condvariable17condvariable.c -lpthread

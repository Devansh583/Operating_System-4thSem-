//orphan process: when the parent process dies
//before the termination of the child process
#include<stdio.h>
#include<unistd.h> //header file to execute unix commands in c
#include<stdlib.h> //for exit() function

int main(void){

    //print the process id of the parent
    printf("Process id of the parent is %d.\n",getpid());

    //making a new process
    int pid=fork();

    //fork return the pid of the child to parent process
    if(pid!=0) //this will be true for parent process
    {
        //parent process will exit before the termination 
        //of the child process
        exit(42);
            
    }
    //fork return 0 to the child process
    else//this will be true of child process
    {
        printf("Process id of the child process is %d.\n",getpid());
    }

    //when the parent process dies then
    //it's child is adopted by init process
    //whose pid is 1
    printf("pid of parent process is %d",getppid());
    return 0;
}
/*
Sample Output
Process id of the parent is 200.
Process id of the child process is 201.
pid of parent process is 1
*/

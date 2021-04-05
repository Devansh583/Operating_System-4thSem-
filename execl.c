//int execl(const char* filename, const char* arg0,...)
//full name of the executable file must be given
//running fork1.c using it's executable file fork1
  
#include<stdio.h> 
#include<unistd.h> 
int main() 
{ 
        execl("/mnt/c/operating_sys/fork1","fork1",NULL); 
      
        /*All statements are ignored after execl() call as this whole  
        process(execl.c) is replaced by another process (fork1.c) 
        */
        printf("Ending-----"); 
      
    return 0; 
} 
/*Sample Output
root@DESKTOP-3V1QJSN:/mnt/c/operating_sys# gcc execl.c
root@DESKTOP-3V1QJSN:/mnt/c/operating_sys# ./a.out
Hello World!
Parent process id 193
Hello, Running first fork 193
Hello, Running first fork 194
*/
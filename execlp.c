//int execlp(const char* filename, const char* arg0,...)
//name of the executable file must be given
//running fork1.c using it's executable file fork1
  
#include<stdio.h> 
#include<unistd.h> 
int main() 
{ 
        execlp("/mnt/c/operating_sys/fork1","fork1","l","-a",NULL);
      
        /*All statements are ignored after execlp() call as this whole  
        process(execlp.c) is replaced by another process (fork1.c) 
        */
        printf("Ending-----"); 
      
    return 0; 
} 
/*Sample Output
root@DESKTOP-3V1QJSN:/mnt/c/operating_sys# gcc execlp.c
root@DESKTOP-3V1QJSN:/mnt/c/operating_sys# ./a.out
Hello World!
Parent process id 59
Hello, Running first fork 59
Hello, Running first fork 60
*/
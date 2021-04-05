//Readers-Writers Problem- Classical Synchronization Problem
//Multiple readers can read a shared object(file) simultaneously
//but multiple writers can not write because it will cause data inconsistency.
//Therefore, writer is given permission in exclusive manner.
//In the write mode, we can do both- read and write.

#include<stdio.h>
#include<stdlib.h>

void read();
void write();
void read_stop();
void write_stop();
void wait(int*);
void signal(int*);
//r_w will be a binary semaphore(writer is given permission in exclusive manner.)
//r will be a counting semaphore(Multiple readers can read a shared object(file) simultaneously)
//mutex will check for reader and writer so that both the operations are exclusive
int r_w,r,mutex,r_count;

int main(void)
{
    //assigning the values to the semaphore
    r_w=1,r=1,mutex=1;

    int choice=0;
    printf("Menu\n 1.Read\n 2.Stop Reading\n 3.Write\n 4.Stop writing\n 5.Exit\n");
    while(1)
    {
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: read();
            break;

            case 2: read_stop(); break;

            case 3: write(); break;

            case 4: write_stop(); break;

            case 5: exit(-1); break;

            default: printf("You have entered wrong choice!!!\n");
        }
    }
    return 0;
}

void read()
{
    //check if writer is not writing
    if(mutex)
    {
        //writer can not write
        wait(&r_w);

        //reader is reading
        wait(&mutex);

        //increment the no. of readers(multiple readers are in shared file)
        r_count++;

        signal(&mutex);
    }
    else{
        printf("Writer is writing.\n");
    }
}

void read_stop()
{
    r_count--; //no. of readers has decreased by one
    //readers have completed their reading
    if(r_count==0) signal(&r_w);
}

void write()
{
    if(mutex && r_w) //check if reader not present in shared file and no other writer is writing in the shared file
    {
        wait(&mutex);
        //reader can not read
        wait(&r);
        //no other writer can enter
        wait(&r_w);
        printf("I am writing.\n");    
    }
    else{
        printf("Reader is reading the shared file or one writer is already writing.\n");
    }
}

void write_stop()
{
    //allow the reader or writer to enter in the shared file
            signal(&mutex);
            signal(&r_w);
            signal(&r);
}

void wait(int* s)
{
    if(*s>0) (*s)--;
}

void signal(int* s)
{
    (*s)++;
}

/*Sample Output
Menu
 1.Read
 2.Stop Reading
 3.Write
 4.Stop writing
 5.Exit
Enter your choice: 1
Enter your choice: 1
Enter your choice: 3
Reader is reading the shared file or one writer is already writing.
Enter your choice: 2
Enter your choice: 1
Enter your choice: 2
Enter your choice: 2
Enter your choice: 3
I am writing.
Enter your choice: 3
Reader is reading the shared file or one writer is already writing.
Enter your choice: 4
Enter your choice: 4
Enter your choice: 3
I am writing.
Enter your choice: 5
*/
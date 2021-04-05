//with the help of Counting Semaphores
//producer produces the element
//consumer consumes that value
//consumer can not consume when nothing to be consumed

#include<stdio.h>
#include<stdlib.h>

# define BUFFER_SIZE 5
//semaphores
int empty,full,mutex;

//wait will decrease the value of semaphore by 1
int wait(int* s)
{
    //printf("%d\n",*s);
    if(*s<=0) 
    {
        printf("You have to wait.\n");
        return 0;
    }
    else (*s)--;
    return 1;
}

int signal(int* s)
{
    //printf("%d\n",*s);
    (*s)++;
}

void producer(short int value);
void consumer();

short int in,out,buffer[BUFFER_SIZE];

int main(void)
{
    //assigning the values to the semaphores
    empty= BUFFER_SIZE, full=0, mutex=1;

    short int i=0,value=0,choice=0;

    printf("Menu\n 1.Produce\n 2.Consume\n 3.Exit\n");
    while(1)
    {
        printf("Enter your choice: ");
        scanf("%hd",&choice);
        switch(choice)
        {
            case 1: printf("Enter the value: ");
                    scanf("%hd",&value);
                    producer(value);
                    break;
            case 2: consumer();
                    break;
            case 3: exit(-1);
                    break;
            default: printf("You have entered wrong choice!!!\n");
                    break;
        }
    }

    return 0;
}

void producer(short int value)
{
    if(wait(&empty)) //if buffer has some empty space
    {
        if(wait(&mutex)) //check if consumer is not consuming and helps in mutual exclusion
        {
            //critical section
            buffer[in]=value;
            //update the value of in
            in=(in+1)%BUFFER_SIZE;
            
            signal(&mutex); //producer has stopped producing- now consumer can consume
            signal(&full); //an element has been added in the buffer
        }
    }
}

void consumer()
{
    if(wait(&full)) //check if the buffer is not empty
    {
        if(wait(&mutex)) //check if the producer is not producing
        {
            printf("Consumed Value is %hd.\n",buffer[out]);
            buffer[out]=0;
            out=(out+1)%BUFFER_SIZE;

            signal(&mutex); //consumer has stopped consuming
            signal(&empty); //buffer elements has decreased by 1
        }
    }
        

}

/*
Sample Output
//Consumer trying to consume from empty buffer
//Message displayed "You have to wait."
Menu
 1.Produce
 2.Consume
 3.Exit
Enter your choice: 1
Enter the value: 12
Enter your choice: 2
Consumed Value is 12.
Enter your choice: 2
You have to wait.
Enter your choice: 3
*/
//producer produces the element
//consumer consumes that value
//consumer can not consume when nothing to be consumed

#include<stdio.h>
#include<stdlib.h>

# define BUFFER_SIZE 5
void producer(short int value);
void consumer();

short int in,out,buffer[BUFFER_SIZE],count;

int main(void)
{
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
    if(count==BUFFER_SIZE)
    {
        printf("Buffer is full.\n");
    }
    else{
        buffer[in]=value;
        in=(in+1)%BUFFER_SIZE;
        count++;
    }
}

void consumer()
{
    if(count==0)
    {
        printf("Buffer is empty!\n");
    }
    else{
        printf("Consumed Value is %hd.\n",buffer[out]);
        buffer[out]=0;
        out=(out+1)%BUFFER_SIZE;
        count--;
    }
}

/*Sample Output
Menu
 1.Produce
 2.Consume
 3.ExitEnter your choice: 2
Buffer is empty!   
Enter your choice: 2
Buffer is empty!
Enter your choice: 1
Enter the value: 10
Enter your choice: 20
You have entered wrong choice!!!
Enter your choice: 1
Enter the value: 10
Enter your choice: 1
Enter the value: 10
Enter your choice: 1
Enter the value: 10
Enter your choice: 1
Enter the value: 10
Enter your choice: 1
Enter the value: 10
Buffer is full.
Enter your choice: 2
Consumed Value is 10.
Enter your choice: 2
Consumed Value is 10.
Enter your choice: 2
Consumed Value is 10.
Enter your choice: 2
Consumed Value is 10.
Enter your choice: 2
Consumed Value is 10.
Enter your choice: 2
Buffer is empty!
Enter your choice: 3
*/
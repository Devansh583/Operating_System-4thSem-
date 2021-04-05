//dining-philospher problem
//Five philosphers are sitting around a circular table having 5 empty bowls
//each infront of the philospher and a rice bowl in the middle of the table.
//A chopstick is also placed on the right hand side of each philospher
//Philospher do only two things think and eat.
//Task is to getting two chopsticks whenever a philospher is hungry.  
//Provided algorithm can suffer from deadlock when all the philosphers are hungry at the
//same time. Only they will be able to get a single chopstick.

#include<stdio.h>
#include<stdlib.h>

//semaphore as the chopsticks
int chopsticks[5];

void hungry(int index)
{
    int flag1=0,flag2=0;
    if(chopsticks[index]>0)
    {
        //update the semaphore value to 0 to show unavilability
        chopsticks[index]=0;
        flag1=1;
    }
    if(chopsticks[(index+1)%5]>0)
    {
        //update the semaphore value to 0 to show unavilability
        chopsticks[(index+1)%5]=0;
        flag2=2;
    }
    if(chopsticks[index]==0 && chopsticks[(index+1)%5]==0 && flag1 &&flag2)
    {
        printf("Philospher %d is eating using %d,%d.\n",index,index,(index+1)%5);
    }
    else{
        printf("Chopsticks are not available.\n");
    }
}

void release_chopstick(int index)
{
    //free the chopstick after use
    //update the semaphore value to 1 again
    chopsticks[index]=1;
    chopsticks[(index+1)%5]=1;
}

int main(void)
{
    printf("Menu\n 1.Hungry\n 2.Free Chopstick\n 3.Exit\n");
    int choice=0,index=0;
    int i=0;
    for(;i<5;i++)
    {
        chopsticks[i]=1;
    }

    while(1)
    {
        printf("Enter the choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: 
            //input the index of the hungry philospher
            printf("Input the index of the hungry philospher: ");
            scanf("%d",&index);
            hungry(index);
            break;

            case 2:
            printf("Input the index of the philospher started rethinking: ");
            scanf("%d",&index);
            release_chopstick(index);
            break;

            case 3:
            exit(2);
            break;

            default: printf("You have entered wrong choice!!!\n");
        }
    } 
    return 0;
}

/*Sample Output
In this case only 0th philospher is able to eat.
In case of other philosphers their left chopstick is acquired by their right philospher
there only one chopstick is available. All other philosphers are starving. 
Menu
 1.Hungry
 2.Free Chopstick
 3.Exit
Enter the choice: 1
Input the index of the hungry philospher: 0
Philospher 0 is eating using 0,1.
Enter the choice: 1
Input the index of the hungry philospher: 1
Chopsticks are not available.
Enter the choice: 1
Input the index of the hungry philospher: 2
Chopsticks are not available.
Enter the choice: 1
Input the index of the hungry philospher: 3
Chopsticks are not available.
Enter the choice: 1
Input the index of the hungry philospher: 4
Chopsticks are not available.
Enter the choice: 3

In this case 0th philospher has released the chopstick after use.
That chopstick is now used by other philospher for eating.
Menu
 1.Hungry
 2.Free Chopstick
 3.Exit
Enter the choice: 1
Input the index of the hungry philospher: 0
Philospher 0 is eating using 0,1.
Enter the choice: 2
Input the index of the philospher started rethinking: 0
Enter the choice: 1
Input the index of the hungry philospher: 1
Philospher 1 is eating using 1,2.
Enter the choice: 3
*/
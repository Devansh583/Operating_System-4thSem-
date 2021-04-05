//peterson algo-1
//used to solve critical section problem
//only applicable for 2 processes
//processes must be interested in alteration to execute CS
//this algo follows mutual exclusion
//but not progress(when only one process in interested to execute CS repeatedly)

#include<stdio.h>

int run_process(int p_no);
//taking a global variable
int turn=0;

int main(void)
{
    //input the choice from the user to run which process
    int choice=0;
    
    int i=0;
    for(i=0;i<10;i++)
    {
        printf("Enter the process no.: ");
        scanf("%d",&choice);

        if(run_process(choice))
        ;
    }
    return 0;
}

int run_process(int p_no)
{
    if(turn != p_no) 
    {
        printf("%d can not execute critical section.\n",p_no);
        return 0;
    }
    printf("%d is executing critical section.\n",p_no);

    //update the value of turn
    if(turn==0) turn=1;
    else turn=0;
    return 1;
}

/*Sample Output
Enter the process no.: 0
0 is executing critical section.
Enter the process no.: 1
1 is executing critical section.
Enter the process no.: 0
0 is executing critical section.
Enter the process no.: 1
1 is executing critical section.
Enter the process no.: 0
0 is executing critical section.
Enter the process no.: 0
0 can not execute critical section.
Enter the process no.: 1
1 is executing critical section.
Enter the process no.: 1
1 can not execute critical section.
Enter the process no.: 1
1 can not execute critical section.
Enter the process no.: 0
0 is executing critical section.
*/
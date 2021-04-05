//peterson algorithm-2
//difference between algo 1 and 2 is that 1 needs alteration of processes
//but 2nd will work without alteration also.
//2nd fails when both the processes are interested simultaneously.
//This arises the problem of deadlock or progress stops.

#include<stdio.h>
#include<stdbool.h>

bool flag[2];

void run_process(int p_no);

int main(void)
{
    //input the choice from the user to run which process
    int p_no=0;
    
    //initializing the flag variables with false
    flag[0]=false,flag[1]=false;

    int i=0;
    for(i=0;i<10;i++)
    {
        printf("Enter the process no.: ");
        scanf("%d",&p_no);

        run_process(p_no);
    }
    return 0;
}

void run_process(int p_no)
{
    flag[p_no]=true; //declare your own interset
    int j=0;
    if(p_no==0) j=1; 
    if(flag[j]) //wait if the other guy is interested
    {
        printf("%d can not execute CS.\n",p_no);
        return ;
    }

    printf("%d is executing CS.\n",p_no);
    flag[p_no]=false; //declare that you lost interest

}
/*Sample Output
Enter the process no.: 0
0 is executing CS.
Enter the process no.: 1
1 is executing CS.
Enter the process no.: 0
0 is executing CS.
Enter the process no.: 1
1 is executing CS.
Enter the process no.: 0
0 is executing CS.
Enter the process no.: 1
1 is executing CS.
Enter the process no.: 0
0 is executing CS.
Enter the process no.: 1
1 is executing CS.
Enter the process no.: 1
1 is executing CS.
Enter the process no.: 0
0 is executing CS.
*/
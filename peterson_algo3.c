//peterson algo-3
//This algo will work even when both process are interested.
//It will give chance to one process at a time which will depend on the value of turn.
#include<stdio.h>
#include<stdbool.h>

int turn;
bool flag[2];

void run_process(short int p_no);

int main(void)
{
    short int i=0,p_no=0;
    flag[0]=false,flag[1]=false;

    for(i=0;i<5;i++)
    {
        printf("Enter the process no.: ");
        scanf("%hd",&p_no);
        run_process(p_no);
    }
    return 0;
}

void run_process(short int p_no)
{
    //declaring the process is interested
    flag[p_no]=true;
    int j=0;
    if(p_no==0) j=1;
    int turn=j;
    if(flag[j]&&turn==j)
    {
        printf("%d can not execute C.S.\n",p_no);
        return;
    }
    printf("%d is executing C.S.\n",p_no);
    flag[p_no]=false; //declare that not interested

} 

/*Sample Output
Enter the process no.: 0
0 is executing C.S.
Enter the process no.: 1
1 is executing C.S.
Enter the process no.: 1
1 is executing C.S.
Enter the process no.: 0
0 is executing C.S.
Enter the process no.: 1
1 is executing C.S.
*/
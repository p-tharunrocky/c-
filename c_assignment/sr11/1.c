/*1. Employees and BreakFast
At the EIC Cafeteria, n employees are standing in the queue. Today, on the menu, we have 
either a plain dosa or a masala dosa. Each employee has a preference. He/She either want to
eat a sada dosa or a masala dosa. At the front end of the queue, there is a stack of dosas, a 
mix of sada and masala dosas. A employee at the front of the queue performs the following 
operation
1. If the employee likes a sada dosa and the top of the stack is a sada dosa, then the 
employee takes the sada dosa and leaves the queue.
2. If the employee likes a masala dosa and the top of the stack is a masala dosa, then the
employee takes the masala dosa and leaves the queue.
3. Else the employee leaves the front of the queue and goes to end of the queue.
This process goes on till no one in the queue is able to leave it. All these employees will not 
be able to have the breakfast today. Your job is to find the number of such employees.
Input: In the input O(zero) will be used to represent a sada dosa and 1(one) represents a 
masala dosa. The first line of the input contains single integer n(1 ≤ n ≤ 10000), the number
of employees in the queue as well as the number of dosas on the stack. The next line 
contains n integers (only 1 and 0) separated by a space. This sequence represents the stack 
where the first element is the top of the stack. The third line contains n numbers a1, a2, . . . ,
an( Each ai is 1 and 0). The first number represents the first person of the queue who like sada
dosa if a1 = 0 or masala dosa if a1 = 1.
Output: The number of employees who will not be able to
have the breakfast. 
 Input : 3
0 1 1
1 0 1
Output : 0
Explanation: The following happensin each iteration:
1. The employee at the front goes to the back. The stack is now [0 1 1] and queue is [0 1 1].
2. The employee at the front takes the sada dosa. The stack is now [1 1] and queue is [1 1].
3. The employee at the front takes the masala dosa. The stack is now [1] and queue is [1].
4. The employee at the front takes the masala dosa. The stack is now [] and queue is [].
*/


#include<stdio.h>
int top=-1,n,f=-1,r=-1;

void push(int stack[])
{
    int k=0;
    if(top!=n-1)
    {
	    top++;
	   printf("enter 0-masala dosa \n 1-sada dosa :");
	   scanf("%d",&k);
	    stack[top]=k;
    }
    else
    {
	   printf("stack is full \n ");
    }
}

void pop(void)
{
	if(top != -1)
	top--;
	else
	   printf("stack is empty \n ");
		
}

void enqueue(int queue[])
{
	int k=0;
        printf("enter the choice of employ 0-masala dosa \n 1-sada dosa :");
	   scanf("%d",&k);
	if(r==-1)
	{
		f++;
		r++;
		queue[f]=k;
	}
	else if(r!=-1 && r!=(n-1))
	{
            		r++;
		queue[r]=k;
	}
	else
        printf("queue is full \n ");
}

void dequeue(void)
{
	if(r!=-1 && r!=f)
	{
		f++;
	}
	else if(r==f)
	{
		r=f=-1;
	}
	else
	   printf("queue is empty \n ");
}

int check(int stack[],int queue[])
{
	int flag=0,i;
	if(stack[top]==queue[f])
	{
		pop();
		dequeue();
	}
	else
	{
		int z=queue[f];
		for(i=f;i<r;i++)
		{
			queue[i]=queue[i+1];
		}
		queue[i]=z;
	}
       for(int i=0;i<top+1;i++)
	{
           for(int j=f;j<r+1;j++)
	   {
		   if(stack[i]==queue[j])
		   {
			   flag++;
			   break;
		   }
	   }
	   if(flag!=0)
		   break;
	}
	if(flag==0 || top==0)
		return 0;
	else 
		return 1;

}

int main()
{
	int i,x;
	printf("enter the max no.of employes : ");
	scanf("%d",&n);
	int stack[n],queue[n];	
	//printf("select \n 0-quit \n 1-enter dosa in stack \n 2-queue members  ");
	scanf("%d",&i);
	while(i)
	{
	//printf("select \n 0-quit 1-enter dosa in stack \n 2-queue members  ");

	switch(i)
	{
	case 0: break;
        case 1:push(stack);
	       break;
        case 2 :enqueue(queue);
	       break;
	default:
	       printf("enter the correct option only \n");
	}
        scanf("%d",&i);
	}
	printf("%d %d  %d\n",top,r,f);
	printf("completed \n");

        x=check(stack,queue);
	while(x)
	{
		x=check(stack,queue);
	      printf("%d %d  %d\n",top,r,f);
	}
	printf("no.of employes left : %d\n",(r-f+1));
}



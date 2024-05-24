/*Implement search function for doubly link list. 
 *author : p.Tharun
 *created : 13/5/2024
 *modified : 13/5/2024
 */
/* REQUIRED HEADER FILES */
#include<stdio.h>
#include<stdlib.h>



typedef struct node
{
	int n;
	struct node *next;
	struct node *prev;
}clist;
clist *head=NULL,*temp=NULL,*ht=NULL,*p=NULL;


/*FUNCTION PROTOTYPES */
void createnode(void);
void search(int );

/** MAIN PROGRAM **/
int main()
{
	int k,y;
	scanf("%d",&k);
	while(k)
	{
		createnode();
		printf("enter 0 for quit: ");
		scanf("%d",&k);
	}
	printf("enter the element to search :");
	scanf("%d",&y);
	search(y);
	//printCList(temp,head); 
}

void createnode(void)
{
	clist *new=(clist *)malloc(sizeof(struct node));
	if(new==NULL)
		printf("error\n");
	printf("enter the element :");
	scanf("%d",&new->n);
	if(head==NULL)
	{
		head=new;
		new->prev=NULL;
		new->next=NULL;
		//ht=head;
	}
	else
	{
		temp->next=new;
		new->prev=temp;
	}
	temp=new;
	//ht=head;
}

void search(int y)
{
	int flag=0;
	p=head;
	while(p!=NULL)
	{
		if(y==p->n)
		{
			printf("element found \n");
			flag=1;
			break;
		}
		p=p->next;
	}
	if(flag!=1)
		printf("element not found\n");
}


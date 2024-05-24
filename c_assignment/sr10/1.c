/*In a circular linked list, the next pointer of the last node points to the starting 
node of the list. Write a recursive C function that prints the elements of a circular 
linked list of integers in the reverse order (that is, from end to beginning). 
Use the following function prototype: 
void printCList ( clist l, const clist h ); 
Here the second parameter points to the beginning of the list and is kept constant 
across the calls. Assume that no dummy header node is used in the circular linked list 
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
void print(void);
void printCList (struct node *l, const struct node *h );

/** MAIN PROGRAM **/
int main()
{
	int k;
	scanf("%d",&k);
	while(k)
	{
	createnode();
	printf("enter 0 for quit: ");
        scanf("%d",&k);
	}
	print();
   printCList(temp,head); 
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
		new->prev=head;
		new->next=head;
		ht=head;
	}
	else
	{
		temp->next=new;
                ht->prev=new;
		new->prev=temp;
		new->next=ht;
	}
	temp=new;
	//ht=head;
}

void print(void)
{
       p=head;
	while(p->next!=head)
	{
		printf("%d ",p->n);
		p=p->next;
	}
		printf("%d \n",p->n);
}

void printCList (struct node *l, const struct node *h )
{	
    while(l!=h)
    {
         printf("%d ",l->n);
        printCList(l->prev,h);
	 break;
    }
   if(l==h)
      printf("%d \n",l->n);
}

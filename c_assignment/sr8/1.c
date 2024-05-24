/*Write a program that allows to build and adapt an alphabetically ordered single-linked list with a 
command interpreter. Part of the code is written below. Only the missing functions need to be 
programmed.*/
#include <stdio.h>
#include <string.h> // needed for strcpy() and strcmp()
#include <stdlib.h> // needed for malloc(), free()
#define STRLEN 64
typedef struct node
{
char name[STRLEN];
struct node *next;
} Node;
void showHelp(void);
void add(char *, Node **);
void removeElement(char *, Node **);
int isItem(char *, Node *);
int countItems(Node *);
void removeList(Node **);
void showList(Node *);
char * trim(char *);
int main(void)
{
char instruction[STRLEN];
Node *head = NULL;
char *pi; // pi = pointer to the instruction2
printf("Test program for a single-linked list.\n");
printf("\nEnter an instruction (h = help)\n");
printf("\n> ");
memset(instruction, '\0', STRLEN);
gets(instruction);
pi = trim(instruction);
while (*pi != 'q')
{
switch (*pi)
{
case 'i': add(trim(pi + 1), &head);
break;
case 'd': removeElement(trim(pi + 1), &head);
break;
case 'f': if (isItem(trim(pi + 1), head))
printf("\"%s\" is in the list.\n", 
trim(pi+1));
else
printf("\"%s\" is NOT in the list.\n",
trim(pi+1));
break;
case 'l': showList(head);
break;
case 'n': printf(" Number of list items: %d\n",
countItems(head));
break;
case 'r': removeList(&head);
break;
case 'h': showHelp();
case 'q': break;
default: printf(" Unknown instruction (h = help)\n");
}
printf("\n> ");
memset(instruction, '\0', STRLEN);
gets(instruction);
pi = trim(instruction);
}
removeList(&head);
return 0;
}
void showHelp(void)
{
printf("i <string> : inserts the element in <string> alphabetically into the list\n");
printf("d <string> : removes the element in <string> from thelist\n");
printf("f <string> : searches the list and returns if the stringis in the list or not.\n");
printf("l : shows the full list\n");
printf("n : returns the number of items in the list\n");
printf("r : removes the full list\n");
printf("h : shows the help menu (this list).\n");
printf("q : end of the program (first remove the list)\n");
}
void add(char *s, Node **b)
{
printf("This function inserts \"%s\" (alphabetically) into the list\n", s);
  // create a new Node using dynamic memory allocation
    Node* newNode = (struct node*)malloc(sizeof(struct node));
        if(newNode==NULL)
		printf("error \n");
    strcpy(newNode->name,s);
    newNode->next=NULL;
    int i=0;
   if((*b)==NULL)
          *b=newNode;
   else
   {
	   struct node *a,*c ;
	   a=c=*b;
		     if(strcmp(c->name,s)>0)
		       {
			   newNode->next=a;
			   *b=newNode;
			   i=1;
          		   }
	   while(c)
	   {

              if((!i)&&strcmp(c->name,s)>0)
		   {

			   newNode->next=c;
			   a->next=newNode;
			   break;
	     	   }
		   if(c->next==NULL)
		   {
		   if(strcmp((c)->name,s)<0)
		   {
			   c->next=newNode;
			   break;
		   }
		   }
		   a=c;
		   c=c->next;
	   }      
       }
   printf("done \n");
}
void removeElement(char *s, Node **b)
{
printf("This function removes \"%s\" from the list\n", s);

}
int isItem(char *s, Node *b)
{
printf("This function searches \"%s\" in the list\n", s);
while(b)
{
	if(strcmp(s,b->name))
      return 1;
	
}
return 0;
}
int countItems(Node *b)
{
	int i=0;
printf("This function returns the number of items in the list\n");
while(b)
{
	i++;
	b=b->next;
}
return i;
}
void removeList(Node **b)
{
Node * p = *b;
while (p != NULL)
{
*b = p->next;
free(p);
p = *b;
}
}
void showList(Node *b)
{
if (b == NULL)
{
printf("The list is EMPTY\n");
}
else
{
printf("The list:\n");
while (b != NULL)
{
printf("%s ", b->name);
b = b->next;
}
}
printf("\n\n");
}
char * trim(char *s)
{
while (*s == ' ') s++;
return s;
}

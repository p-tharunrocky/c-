/*Write a program that asks the user to enter the name and the home town of 3 persons. Name and 
home town are stored in a structure Person. The 3 persons are stored in an array. Afterwards, the 
program asks the user to enter a name and searches the town that person lives in.*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char * ito(int a);
      char str[10];
struct search
{
	char arr1[30];
	int age,salary;
};

int main()
{
	int n;
printf("How many people do you want to enter? ");
scanf("%d",&n);
struct search p1[n];
FILE *fp=fopen("abc.txt","w");
for(int i=0;i<n;i++)
{
	char str[100];
	printf("enter the person%d name :",i+1);
	scanf(" %[^\n]s",p1[i].arr1);
	printf("enter the person%d age :",i+1);
	scanf("%d",&p1[i].age);
	printf("enter the person%d salary :",i+1);
	scanf("%d",&p1[i].salary);
	strcpy(str,p1[i].arr1);
         strcat(str," ");
	strcat(str,ito(p1[i].age));
         strcat(str," ");
	strcat(str,ito(p1[i].salary));
           strcat(str,"\n");
	fwrite(str , 1 , strlen(str) , fp );
}
}

char* ito(int a)
{
	int r,i=0;

    while(a)
    {
	    str[i++]=(char)(a%10+48);
	    a/=10;
    }
    str[i]='\0';
   int l=strlen(str);
   for(int i=0,j=l-1;i<=j;i++,j--)
   {
	   char temp;
	  temp=str[i];
	  str[i]=str[j];
	  str[j]=temp;
   }
    return &str[0];
}


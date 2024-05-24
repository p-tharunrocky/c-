/*Write a program that asks the user to enter the name and the home town of 3 persons. Name and 
home town are stored in a structure Person. The 3 persons are stored in an array. Afterwards, the 
program asks the user to enter a name and searches the town that person lives in.*/

#include<stdio.h>
#include<string.h>
void readperson(void);
int searchtown(char *arr1,char *arr2);
struct search
{
	char arr1[30],arr2[30];
}p1[3];
int main()
{
char str[20];
int i=0;
readperson();
printf("Enter the name of the person you want to search for:");
scanf(" %[^\n]s",str);
for(i=0;i<3;i++)
{
	if(searchtown(p1[i].arr1,str)==1)
		break;
}
     if(i!=3)
        printf("villge name for %s is %s \n",p1[i].arr1,p1[i].arr2);
	else
	printf("name not found \n");
}

int searchtown(char *arr1,char *arr2)
{
	if(!(strcmp(arr1,arr2)))
			return 1;
	return 0;
}



void readperson(void)
{
for(int i=0;i<3;i++)
{
	printf("enter the person%d name :",i+1);
	scanf(" %[^\n]s",p1[i].arr1);
	printf("enter the person%d village :",i+1);
	scanf(" %[^\n]s",p1[i].arr2);
}
}

/*Write a program that asks the user to enter the name and the home town of 3 persons. Name and 
home town are stored in a structure Person. The 3 persons are stored in an array. Afterwards, the 
program asks the user to enter a name and searches the town that person lives in.*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int n;
	char c[2];
FILE *fp=fopen("abc.txt","r");

  while(fread(c,1,1, fp ))
  {
	printf("%c",c[0]);
  }
}


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
        if(argc!=3)
        {
                printf("no input files are provided\n");
                return 0;
        }
        int cnt=0;
        char ptr1[100],ptr2[100];
        FILE *fp1=NULL,*fp2=NULL;
        fp1=fopen(argv[1],"r");
        fp2=fopen(argv[2],"r");
        if(fp1==NULL)
        {
                puts("file not created");
                exit(0);
        }
        if(fp2==NULL)
        {
                puts("file not created");
                exit(0);
        }
        fgets(ptr1,100,fp1);
        fgets(ptr2,100,fp2);
        int i=0;
        do
        {
                i++;
                int fin=strcmp(ptr1,ptr2);
                if(fin)
                {
                        printf("%d %s",i,ptr1);
                        printf("%d %s",i,ptr2);
                        cnt++;
 
                }
                if(i==10)
                {
                        printf("the file is execced 10th line\n");
                        exit(0);
                }
        }
        while(fgets(ptr1,100,fp1)&&fgets(ptr2,100,fp2));
        while(fgets(ptr1,100,fp1))
        {
                printf("%d %s",++i,ptr1);
                cnt++;
        }
        while(fgets(ptr2,100,fp2))
        {
                printf("%d %s",++i,ptr2);
                cnt++;
        }
        fclose(fp1);
        fclose(fp2);
        if(cnt==0)
                puts("Both files are identical");
}


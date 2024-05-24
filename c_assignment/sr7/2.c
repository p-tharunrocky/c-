#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cnt;
struct dob
{
        int date;
        int month;
        int year;
};
struct person
{
        char name[20];
        struct dob dat;
};
struct person *readperson(char *file,struct person *p)
{
        FILE *fp;
        fp=fopen(file,"r");
        do
        {
                p=realloc(p,(cnt+1)*sizeof(struct person));
                fscanf(fp,"%s %d %d %d",p[cnt].name,&p[cnt].dat.date,&p[cnt].dat.month,&p[cnt].dat.year);
                cnt++;
        }
        while(!feof(fp));
        cnt--;
        return p;
}
int arr[2];
int* calucalte(struct person *p,int d,int m,int y)
{
        int d1;
        int len=strlen(p[0].name);
        if(d>p[0].dat.date)
                d1=d-p[0].dat.date;
        else
                d1=d+31-p[0].dat.date;
        int m1;
        if(m>p[0].dat.month)
                m1=m-p[0].dat.month;
        else
                m1=m+12-p[0].dat.month;
        int y1=y-p[0].dat.year;
        printf("%s age is %d days %d months %d years\n",p[0].name,d1,m1,y1);
        int ret=0;
        for(int i=1;i<cnt;i++)
        {
                if(len<strlen(p[i].name))
                {
                        arr[0]=i;
                        len=strlen(p[i].name);
                }
 
                int d2;
                if(d>p[i].dat.date)
                {
                        d2=d-p[i].dat.date;
                }
                else
                        d2=d+31-p[i].dat.date;
                int m2;
                if(m>p[i].dat.month)
                        m2=m-p[i].dat.month;
                else
                        m2=m+12-p[i].dat.month;
                int y2=y-p[i].dat.year;
 
                printf("%s age is %d days %d months %d years\n",p[i].name,d2,m2,y2);
                if(y2>y1||m2>m1||d2>d1)
                {
                        y1=y2;
                        m1=m2;
                        d1=d2;
                        ret=i;
                }
        }
        arr[1]=ret;
        return arr;
}
int main(int argc,char *argv[])
{
        struct person *db=NULL;
        int *ret;
        char *ptr;
        if(argc!=5)
        {
                puts("not enough inputs\n");
                return 0;
        }
        db=readperson(argv[1],db);
        int pdate=atoi(argv[2]);
        int pmonth=atoi(argv[3]);
        int pyear=atoi(argv[4]);
        ret=calucalte(db,pdate,pmonth,pyear);
 
        printf("The %s the long age and the longest name is %s\n",db[ret[1]].name,db[ret[0]].name);
}

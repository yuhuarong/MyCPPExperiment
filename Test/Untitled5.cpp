#include<stdio.h>
#include<string.h>

void count(char *n,int *a,int *b,int *c)
{
	int i;
	for(i=0;i<strlen(n);i++)
	{
		if((*(n+i)>='A'&&*(n+i)<='Z')||(*(n+i)>='a'&&*(n+i)<='z'))
		{
			(*b)++;
		}
		else if(*(n+i)>='0'&&*(n+i)<='9')
		{
			(*a)++;
		}
		else
		{
			(*c)++;
		}
	}
}
int main()
{
	char num[100];
	int a,b,c;
	a=b=c=0;
	gets(num);
	count(num,&a,&b,&c);
	printf("%d %d %d \n",a,b,c);
	return 0;
}

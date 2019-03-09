#include<stdio.h>

int main()
{
	int a=2;
	
	while(scanf("%d",&a)){
		if(a<0)
		{
			printf("a小于0");
		}
		else if(a<10)
		{
			printf("a大于等于0且a小于10");
		}
		else
		{
			printf("a大于等于10");
		} 
		printf("\n");
	}
	return 0;
}

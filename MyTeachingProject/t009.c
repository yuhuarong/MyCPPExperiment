#include<stdio.h>

int main()
{
	int a=2;
	
	while(scanf("%d",&a)){
		if(a<0)
		{
			printf("aС��0");
		}
		else if(a<10)
		{
			printf("a���ڵ���0��aС��10");
		}
		else
		{
			printf("a���ڵ���10");
		} 
		printf("\n");
	}
	return 0;
}

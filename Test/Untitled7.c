#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
	char ch[100][100];
	int i,n,h,s,w,h1,c,x;
	int num[100][100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%c%d %c%d",&ch[i][0],&num[i][0],&ch[i][1],&num[i][1]);
	}
	for(i=0;i<n;i++)
	{
		h=abs(ch[i][0]-ch[i][1]);
		s=abs(num[i][0]-num[i][1]);
		w=abs(h-s)+abs((h+s-abs(h-s)))/2;
		x=0;
		c=0;
		//printf("%d %d %d %d %d\n",h,s,w,ch[i][0],ch[i][1]);
		if(h==0||s==0)
		{
			h1=1;
			x=2;
			c=1;
		}
		else if(abs(h-s)) 
		{
			h1=2;
		}
		else
		{
			h1=1;
		}
		if(!c)
		{
			c=2;
		}
		if((h+s)%2==0&&x==0)
		{
			if(h==s)
			{
				x=1;
			}
			else
			{
				x=2;
			}
			printf("%d %d %d %d\n",w,h1,c,x);
		}
		else
		{
			printf("%d %d %d Inf\n",w,h1,c);
		}
	}
	return 0;
}

#include<stdio.h>

int main(){
	char ch1[100]={'0'},ch2[100]={'0'},ch3[100];
	int a,b,i,c;
	c=0;
	scanf("%s%s",ch1,ch2);
	for(i=0;ch1[i]!='0'||ch2[i]!='0';i++){
		a=ch1[i];
		b=ch2[i];
		if(c){
			a++;
		}
		if((a+b)>=10){
			ch3[i]=a+b+38;
			c=1;
		}
		else{
			ch3[i]=a+b+48;
			c=0;
		}
	}
	printf("%s\n",ch3);
	//scanf("%d",&ch1[0]);
	//printf("%c",ch1[0]+1);
	return 0;
}


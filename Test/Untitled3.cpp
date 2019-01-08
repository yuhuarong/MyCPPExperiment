#include<stdio.h>

void copy(char *s1,char *s2,int m){
	m--;
	for(;*s2=*(s1+m);s1++,s2++){
		if(*(s1+m)=='\0'){
			break;
		}
	}
}

int main(){
	char c[100],s[100];
	int n;
	gets(c);
	scanf("%d",&n);
	copy(c,s,n);
	printf("%s\n",s);
}

#include<stdio.h>
#include<string.h>

struct Student{
	char id[30];
	char name[30];
	char sex;
	int year,month,day;
	float x,y,z;
	
}stu[100];

int main(){
	int n;
	scanf("%d",&n);
	char find[30];
	float sum=0;
	for(int i=0;i<n;i++){
		//cin>>stu[i].id>>stu[i].name>>stu[i].sex>>stu[i].year>>stu[i].month>>stu[i].day>>stu[i].x>>stu[i].y>>stu[i].z;
		scanf("%s%s%c%d%d%d%f%f%f",stu[i].id,stu[i].name,&stu[i].sex,&(stu[i].year),&(stu[i].month),&(stu[i].day),&(stu[i].x),&(stu[i].y),&(stu[i].z));
	}
	
	scanf("%s",find);
	
	for(int i=0;i<n;i++){
		if(strcmp(stu[i].id,find)==0){
			sum=stu[i].x+stu[i].y+stu[i].z;
			printf("%s %s %c %d %d %d %f %f %f %f",stu[i].id,stu[i].name,stu[i].sex,stu[i].year,stu[i].month,stu[i].day,stu[i].x,stu[i].y,stu[i].z,sum);
			break;
		}
	}
	return 0;
}

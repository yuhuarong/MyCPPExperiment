#include<iostream>

struct student {
	char id[50];
	char name[40];
	char xb;
	float score[3];
}stu;
void sr()
{
	std::cin>>stu.id>>stu.name>>stu.xb>>stu.score[0]>>stu.score[1]>>stu.score[2];
}
void sc()
{
	printf("%s %s %c %.2f %.2f %.2f %.2f %.2f", stu.id, stu.name, stu.xb, stu.score[0], stu.score[1], stu.score[2], (stu.score[0] + stu.score[1] + stu.score[2]) / 3.0, stu.score[0] + stu.score[1] + stu.score[2]);
}
int main()
{
	sr();
	sc();
	return 0;
}

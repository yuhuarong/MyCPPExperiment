#include "friend_test.h"
int main()
{
	clock t1(10,13,56); //定义clock类对象t1
	Date d1(12,25,2004); //定义Date类对象d1
	t1.display(d1); //调用t1中的display函数，实参是Date类对象d1
	return 0;
}

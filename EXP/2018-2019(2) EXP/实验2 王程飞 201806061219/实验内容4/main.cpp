#include "studentA.h"
#include "studentB.h"
#include <iostream>
using namespace std;

void A(){
	StudentA stu1,stu2("Jennie Mao"),stu3(stu2),stu4("John Smith");
	cout<<"stu1:"<<stu1.getName()<<endl;
	cout<<"stu2:"<<stu2.getName()<<endl;
	cout<<"stu3:"<<stu3.getName()<<endl;
	cout<<"stu4:"<<stu4.getName()<<endl;
	
	stu1=stu4;
	
	cout<<"stu1:"<<stu1.getName()<<endl;
	
	stu1.changeName("Peter");
	cout<<"stu1:"<<stu1.getName()<<endl;
	
	stu3.changeName("Tom");
	cout<<"stu3:"<<stu3.getName()<<endl;
	
}

void B(){
	StudentB stu1,stu2("Jennie Mao"),stu3(stu2),stu4("John Smith");
	cout<<"stu1:"<<stu1.getName()<<endl;
	cout<<"stu2:"<<stu2.getName()<<endl;
	cout<<"stu3:"<<stu3.getName()<<endl;
	cout<<"stu4:"<<stu4.getName()<<endl;
	
	stu1=stu4;
	
	cout<<"stu1:"<<stu1.getName()<<endl;
	
	stu1.changeName("Peter");
	cout<<"stu1:"<<stu1.getName()<<endl;
	
	stu3.changeName("Tom");
	cout<<"stu3:"<<stu3.getName()<<endl;
}

int main()
{
	cout<<"A"<<endl;A();cout<<endl;
	cout<<"B"<<endl;B();
	return 0;
}

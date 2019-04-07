#include <iostream>
#include "Ex1.cpp"
#include "Ex2.cpp"
using namespace std;
 
int main() {
	//Ex1 µÄ²âÊÔ 
	Ex1 ex1_1(3), ex1_2(ex1_1), ex1_3(4);
	cout<<"ex1_1 : "<<ex1_1.getX()<<endl;
	ex1_1=ex1_3;
	cout<<"ex1_1 : "<<ex1_1.getX()<<endl;
	cout<<"ex1_2 : "<<ex1_2.getX()<<endl;
	cout<<"ex1_3 : "<<ex1_3.getX()<<endl;
	//Ex2 µÄ²âÊÔ 
	Ex2 ex2_1(4), ex2_2(ex2_1), ex2_3(5);
	cout<<"ex2_1 old : "<<ex2_1.getX()<<endl;
	ex2_1=ex2_3;
	cout<<"ex2_1 new : "<<ex2_1.getX()<<endl;
	cout<<"ex2_2 : "<<ex2_2.getX()<<endl;
	cout<<"ex2_3 : "<<ex2_3.getX()<<endl;
	
	return 0;
}

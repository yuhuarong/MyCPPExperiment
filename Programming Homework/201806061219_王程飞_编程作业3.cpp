#include <iostream> 
using namespace std;

int main()
{
	float height,weight,standard;
	cout << "请输入你的身高（cm）和体重（kg） : " << endl;
	cin >> height >> weight; 
	standard = height - 110;
	if (weight<=standard-5)
	{
		cout << "过瘦" << endl;
	}else if (weight>standard-5&&weight<standard+5)
	{
		cout << "标准" << endl;
	}else if (weight>=standard+5)
	{
		cout << "过胖" << endl;
	}
	
	return 0; 
}

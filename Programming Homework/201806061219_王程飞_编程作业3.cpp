#include <iostream> 
using namespace std;

int main()
{
	float height,weight,standard;
	cout << "�����������ߣ�cm�������أ�kg�� : " << endl;
	cin >> height >> weight; 
	standard = height - 110;
	if (weight<=standard-5)
	{
		cout << "����" << endl;
	}else if (weight>standard-5&&weight<standard+5)
	{
		cout << "��׼" << endl;
	}else if (weight>=standard+5)
	{
		cout << "����" << endl;
	}
	
	return 0; 
}

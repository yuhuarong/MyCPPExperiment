#include<iostream>
using namespace std;

class Student  //����Student��
{
public:
  	Student(int n,int a,float s):num(n),age(a),score(s){} 
  	//���幹�캯��
  	void total();
	float average(); //������̬��Ա����
	static float sum; //��̬���ݳ�Ա
	static int count; //��̬���ݳ�Ա
private:
	int num;
	int age;
	float score;

};

void Student::total() //����Ǿ�̬��Ա����
{ sum+=score; //�ۼ��ܷ�
  count++; //�ۼ���ͳ�Ƶ�����
}

float Student::average() //���徲̬��Ա����
{
	return(sum/count); 
}
float Student::sum=0; //�Ծ�̬���ݳ�Ա��ʼ��
int Student::count=0; //�Ծ�̬���ݳ�Ա��ʼ��

int main()
{
	//����������鲢��ʼ��
	Student stud[3]={ Student(1001,18,70),Student(1002,19,78),Student(1005,20,98) };
	int n;
	cout<<"please input the number of students:";
	cin>>n; //������Ҫ��ǰ�������ѧ����ƽ���ɼ�
	for(int i=0;i<n;i++) //����3��total����
		stud[i].total();
	cout<<"the average score of "<<n<<" students is "<<Student::average()<<endl;
	//���þ�̬��Ա����
	return 0;
}


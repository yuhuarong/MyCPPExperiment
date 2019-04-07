#include <iostream>
#include "SupperArray_int.cpp"
using namespace std;

ostream& operator<<(ostream & out, SupperArray& obj){
	for(int i=0;i<obj.get_size()-1;i++){
		out<<obj[i]<<", ";
	}
	cout<<obj[obj.get_size()-1];
	out<<endl;
	return out;
}
//��������е�����Ԫ��,obj���ﲻ����Ƴ�const��˼��Ϊʲô

SupperArray& operator+(SupperArray& left, SupperArray& right){
	SupperArray *s=new SupperArray(left.get_size()+right.get_size(),0);
	for(int i=0;i<left.get_size();i++){
		(*s)[i]=left[i];
		//cout<<s->get_size()<<" "<<i<<" "<<(*s)[i]<<endl;
	}
	for(int i=left.get_size();i<left.get_size()+right.get_size();i++){
		(*s)[i]=right[i-left.get_size()];
		//cout<<s->get_size()<<" "<<i<<" "<<(*s)[i]<<endl;
	}
	return *s;
}
//��ʾ��left��right��ƴ�ӽ�������ӿ�����left��right�Ĳ���

//SupperArray  operator-(SupperArray& left, SupperArray & right); 
//��ʾ��left��right�Ĳ��ѡ��

int main()
{
	int a[10]={45,36,78,81,12,7,66,35,27,9},b[10]={23,16,76,98,43,88,26,90,41,8};
	int loop;
	SupperArray aArray,bArray;
	for(loop=0;loop<aArray.get_size();++loop)
	{	
		aArray[loop]=a[loop];
	    bArray[loop]=b[loop];
	}
	cout<<aArray;	
	aArray.sort();
	cout<<aArray;
	//cout<<bArray;
	
	SupperArray cArray(aArray+bArray);
	cout<<cArray;

    return 0;
}

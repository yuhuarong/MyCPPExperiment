#include <iostream>
#include "SupperArray_template.cpp"
using namespace std;

template<class T>
ostream& operator<<(ostream& out, SupperArray<T>& obj){
	for(int i=0;i<obj.get_size()-1;i++){
		out<<obj[i]<<", ";
	}
	out<<obj[obj.get_size()-1]<<endl;
	return out;
}
//输出数组中的所有元素

template<class T>
SupperArray<T>  operator+(SupperArray<T>& left, SupperArray<T>& right){
	SupperArray<T> *s=new SupperArray<T>(left.get_size()+right.get_size(),0);
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
 //表示求left和right的拼接结果，复杂可以求left和right的并集

int main()
{
	int a[10]={45,36,78,81,12,7,66,35,27,9},b[10]={23,16,76,98,43,88,26,90,41,8};
	char ac[10]={'a','f','c','j','e','b','i','h','g','d'},bc[10]={'t','l','z','o','m','k','n','y','u','v'};
	int loop;
	SupperArray<int> aArray,bArray;
	for(loop=0;loop<aArray.get_size();++loop)
	{	
		aArray[loop]=a[loop];
		bArray[loop]=b[loop]; 
	}
	cout<<aArray;	
	aArray.sort();
	cout<<aArray;
	
	SupperArray<int>  cArray(aArray+bArray);
	cout<<cArray;
    
	SupperArray<char> acArray,bcArray;
	for(loop=0;loop<aArray.get_size();++loop)
	{
		acArray[loop]=ac[loop];
	    bcArray[loop]=bc[loop]; 
	}
	cout<<acArray;	
	acArray.sort();
	cout<<acArray;
	
	SupperArray<char> ccArray(acArray+bcArray);
	cout<<ccArray;

    return 0;
}

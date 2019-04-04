#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

/*
int max_of_array(int a[], int n){
	sort(a,a+n);
	return a[n-1];
}
*/

template<class T>
T max_of_array(T a[],int n){
	sort(a,a+n);
	return a[n-1];
}

int main()
{
	char c[]="I love c++ programming.";
	int a[20]={3,4,56,78,99,12,34,67,89,22,33,44,10,67,55,33,45,32,21,11};

	cout<<max_of_array(c,strlen(c))<<endl;
	cout<<max_of_array(a,20)<<endl;

	return 0;
}


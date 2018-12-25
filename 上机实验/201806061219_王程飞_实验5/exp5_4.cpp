#include<iostream>
#include<cmath>
using namespace std;

float clacArea(float a, float b, float c){
	float p=(a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}


int main(){
	float a, b, c;
	cin>>a>>b>>c;
	cout<<clacArea(a, b, c)<<endl;
	
	return 0;
}


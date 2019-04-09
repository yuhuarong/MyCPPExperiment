#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){
	double a,b,c,d,r;
	while(cin>>a>>b>>c>>d){
		r=sqrt((a-c)*(a-c)+(b-d)*(b-d));
		cout<<setiosflags(ios::fixed)<<setprecision(2)<<r<<endl;
	}
}

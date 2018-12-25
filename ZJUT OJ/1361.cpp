#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
	float x1,x2,y1,y2;
	float line;
	while(cin>>x1>>y1>>x2>>y2){
		line=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		cout<<setiosflags(ios::fixed)<<setprecision(2)<<line<<endl;
	}
	
	return 0;
}

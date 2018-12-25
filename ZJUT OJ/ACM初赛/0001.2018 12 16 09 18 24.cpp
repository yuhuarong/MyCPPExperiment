#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int isTran(float a,float b,float c){
	return (a+b>c&&a+c>b&&b+c>a)&&(abs(a-b)<c&&abs(c-b)<a&&abs(a-c)<b);
}

double getl(int x1,int y1,int x2,int y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

double getS(double a,double b,double c){
	float p=(a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}

int main() {
	int T,x1,y1,x2,y2,x3,y3;double la,lb,lc,R,r,s;
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>x1>>y1>>x2>>y2>>x3>>y3;
		la=getl(x1,y1,x2,y2),lb=getl(x1,y1,x3,y3);lc=getl(x2,y2,x3,y3);
		if(isTran(la,lb,lc)){
			s=getS(la,lb,lc);
			r=2*s/(la+lb+lc);
			R=(la*lb*lc)/(4*s);
			cout<<fixed<<setprecision(3)<<(R*R)/(r*r)<<endl;
		} else {
			cout<<"NO SOLUTION"<<endl;
		}
	}
	
	return 0;
}

#include<fstream>
#include<iostream>
using namespace std;

int isPrime(int n){
	if(n==2){
		return true;
	}
	for(int i=2; i<n; i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
} 

int main() {
	ofstream out("prime.txt", ios::out);
	int n=0;
	if(out){
		for(int i=2;i<2000;i++){
			if(isPrime(i)){
				n++;
				out<<i<<",";
				if(n%10==0){
					out<<endl;
				}
			}
		} 
		cout<<"write successfully"<<endl;
		out.close();
	} else {
		exit(1);
	}

	ifstream in("prime.txt", ios::in);
	int a[10000];
	char c;
	int sum=0;
	if(in){
		for(int i=0;i<n;i++){
			in>>a[i]>>c;
			sum+=a[i];
			cout<<a[i]<<",";
			if((i+1)%10==0){
				cout<<endl;
			} 
		}
		cout<<endl;
		cout<<"read successfully"<<endl;
		cout<<"sum : "<<sum<<endl;
		in.close();
	} else {
		exit(1);
	}
	return 0;
}

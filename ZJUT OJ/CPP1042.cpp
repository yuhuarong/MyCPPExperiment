#include<iostream>
using namespace std;

int main(){
	int f,l,d;
	
	while(cin>>f>>l>>d&&(f||l||d)){
		int sum=(f+l)*((l-f)/d+1)/2;
		cout<<sum<<endl;
	}
}
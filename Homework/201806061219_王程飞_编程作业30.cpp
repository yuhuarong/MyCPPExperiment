#include<iostream>
using namespace std;

struct Clock{
	int h,m,s;
};

int main(){
	Clock *clocks=new Clock[2];
	cin>>clocks[0].h>>clocks[0].m>>clocks[0].s;
	cin>>clocks[1].h>>clocks[1].m>>clocks[1].s;
	
	for(int i=0;i<2;i++){
		if(clocks[i].s<59){
			clocks[i].s++;
		} else {
			clocks[i].s=0;
			if(clocks[i].m<59){
				clocks[i].m++;
			} else {
				clocks[i].m=0;
				if(clocks[i].h<23){
					clocks[i].h++;
				} else {
					clocks[i].h=0;
				} 
			} 
		}
		
		cout<<clocks[i].h<<" "<<clocks[i].m<<" "<<clocks[i].s<<endl;
	}
	
	return 0;
} 

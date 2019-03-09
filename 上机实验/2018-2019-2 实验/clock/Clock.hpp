#include <iostream>
using namespace std;

class Clock{
	public:
		double diff(const Clock &clock);
		void init(int h,int m,int s){ this->h=h;this->m=m;this->s=s; }
		void init(){ 
			cout<<"ÊäÈëÊ±¼äh, m, s"<<endl;
			do{ cin>>h>>m>>s; }while(h<0||h>24||m<0||m>59||s<0||s>59);
			init(h, m, s); 
		}
		long normlize() const{
			return h*60+m;
		}
		
		void toString(){
			cout<<h<<":"<<m<<":"<<s; 
		}
	private:
		int h;
		int m;
		int s;
		
};

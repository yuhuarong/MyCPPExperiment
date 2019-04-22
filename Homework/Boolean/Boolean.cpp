#include<iostream>
using namespace std;

class Boolean{
	public:
		Boolean(){
			flag=0;
		}
		template<class T>
		Boolean(T flag){
			if(flag!=0){
				this->flag=1;
			} else {
				this->flag=0;
			}
		} 
		
		//friend ostream& operator<<(ostream& out, const Boolean& b);
		int getFlag(){
			return flag;
		}
		void setFlag(int i){
			if(flag){
				this->flag=1;
			} else {
				this->flag=0;
			}
		}
	private:
		int flag;
};


ostream& operator << (ostream& out,Boolean& b){
	out<<((b.getFlag()!=0)?"true":"false");
	return out;
}

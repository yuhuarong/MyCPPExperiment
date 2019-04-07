#include <iostream>
#include<algorithm>
using namespace std;

class SupperArray{
	public:
		//构造系列
		SupperArray(unsigned n=10,int value=0){
			size=n;
			data=new int[size];
			for(int i=0;i<size;i++){
				data[i]=value;
			}
		}
	    SupperArray(const SupperArray& obj){
	    	size=obj.size;
	    	data=new int[size];
	    	for(int i=0;i<size;i++){
				data[i]=obj[i];
			}
		}
		//赋值重载
		SupperArray& operator=(const SupperArray& right){
			size=right.size;
			delete[] data;
			data=new int[size];
	    	for(int i=0;i<size;i++){
				data[i]=right[i];
			}
			return *this;
		}
	    //下标运算
		int& operator[](unsigned index) const{
			return data[index];
		}
	    //调整容量
		void set_size(unsigned newsize){
			int *tmp=new int[newsize];
	    	for(int i=0;i<size;i++){
				tmp[i]=data[i];
			}
			for(int i=size;i<newsize;i++){
				tmp[i]=0;
			}
			delete[] data;
			data=tmp;
			size=newsize;
		}
		//获取容量
		int get_size() const{
			return size;
		}
	
	    //也可以用下面两个函数代替
		//void expand(unsigned delta);//调整容量到size+delta
		//void subtract(unsigned delta);//调整容量到size-delta
	
        void sort(){	
			for(int i=0;i<size;i++){
				int min=i;
				for(int j=i+1;j<size;j++){
					if(data[j]<data[min]){
						min=j;
					}
				}
				int temp=data[min];
				data[min]=data[i];
				data[i]=temp;
			}
		}
    	//析构
		~SupperArray(){
			delete[] data;
		}
		friend ostream& operator<<(ostream & out,const SupperArray& obj);
		friend SupperArray& operator+(SupperArray& left, SupperArray& right);
	private:
		int *data;
		int size;
};


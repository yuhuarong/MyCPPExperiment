#include <iostream>
#include<algorithm>
using namespace std;

class SupperArray{
	public:
		//����ϵ��
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
		//��ֵ����
		SupperArray& operator=(const SupperArray& right){
			size=right.size;
			delete[] data;
			data=new int[size];
	    	for(int i=0;i<size;i++){
				data[i]=right[i];
			}
			return *this;
		}
	    //�±�����
		int& operator[](unsigned index) const{
			return data[index];
		}
	    //��������
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
		//��ȡ����
		int get_size() const{
			return size;
		}
	
	    //Ҳ����������������������
		//void expand(unsigned delta);//����������size+delta
		//void subtract(unsigned delta);//����������size-delta
	
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
    	//����
		~SupperArray(){
			delete[] data;
		}
		friend ostream& operator<<(ostream & out,const SupperArray& obj);
		friend SupperArray& operator+(SupperArray& left, SupperArray& right);
	private:
		int *data;
		int size;
};


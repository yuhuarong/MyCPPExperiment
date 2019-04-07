#include <iostream>
using namespace std;

template<class T>
class SupperArray{
	public:
		//����ϵ��
		SupperArray(unsigned n=10){
			size=n;
			data=new T[size];
		} 
		SupperArray(unsigned n,T value){
			size=n;
			data=new T[size];
			for(int i=0;i<size;i++){
				data[i]=value;
			}
		}
	    SupperArray(const SupperArray& obj){
	    	size=obj.size;
	    	data=new T[size];
	    	for(int i=0;i<size;i++){
				data[i]=obj[i];
			}
		}
	
		//��ֵ����
		SupperArray& operator=(const SupperArray& right){
			size=right.size;
			delete[] data;
			data=new T[size];
	    	for(int i=0;i<size;i++){
				data[i]=right[i];
			}
			return *this;
		}
	    //�±�����
		T& operator[](unsigned index) const{
			return data[index];
		}
	    //��������
		void set_size(unsigned newsize){
			T *tmp=new T[newsize];
	    	for(int i=0;i<size;i++){
				tmp[i]=data[i];
			}
			delete[] data;
			data=tmp;
			size=newsize;
		}
		
		int get_size() const {
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
		template<class S> friend ostream& operator<<(ostream& out, SupperArray& obj);
		template<class S> friend SupperArray& operator+(SupperArray& left, SupperArray& right);
	private:
		T *data;
		int size;
};

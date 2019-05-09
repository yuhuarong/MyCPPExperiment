#include <iostream>
#include<fstream>
#include<algorithm>
using namespace std;

struct Student{
	char name[10];
	int age;
	int score_1;
	int score_2;
	int score_3;
	float avg;
	int rank; 
};

int main() {
	
	ifstream in("student.txt", ios::in);
	Student student[10];
	int n=0;
	if(in){
		while(in>>student[n].name>>student[n].age>>student[n].score_1>>student[n].score_2>>student[n].score_3){
			student[n].avg=(student[n].score_1+student[n].score_2+student[n].score_3)/3.0;
			//cout<<student[n].avg<<endl;
			n++;
		}
		int m;
		for(int i=0;i<n;i++){
			m=i;
			for(int j=i+1;j<n;j++){
				if(student[m].avg<student[j].avg){
					m=j;
				}
			}
			if(m!=i){
				swap(student[i], student[m]);
			}
		} 
		for(int i=0;i<n;i++){
			student[i].rank=i+1;
		}
		cout<<"read successfully"<<endl;
		in.close();
	} else {
		exit(1);
	}
	
	ofstream out("student_sort.txt", ios::out);
	if(out){
		for(int i=0;i<n;i++){
			out<<student[i].name<<' '<<student[i].age<<' '<<student[i].score_1<<' '<<student[i].score_2<<' '<<student[i].score_3<<' '<<student[i].avg<<' '<<student[i].rank<<endl;
		}
		cout<<"write successfully"<<endl;
		out.close();
	} else {
		exit(1);
	}

	return 0;
}

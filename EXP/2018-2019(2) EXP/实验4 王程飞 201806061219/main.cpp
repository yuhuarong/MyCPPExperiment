#include <iostream>
#include "Node.cpp"
using namespace std;

int main() {
	ElementType a[10]={56,34,3,67,89,55,22,43,12,9};
	
	//��ʼ������ 
	Node* list=new Node(a[0]);
	Node* end=list;
	for(int i=1;i<10;i++){
		end->next=new Node(a[i]);
		end=end->next;
	} 
	
	Node* temp = list; 
	while(temp){
		cout<<temp->data<<endl;
		temp=temp->next;
	}
	cout<<endl;
	
	//89�����72 
	temp=list;
	while(temp->data!=89){
		temp=temp->next;
	}
	Node* t=new Node(72,temp->next);
	temp->next=t;
	temp = list; 
	while(temp){
		cout<<temp->data<<endl;
		temp=temp->next;
	}
	cout<<endl;
	
	//22ǰ����90 
	temp=list;
	Node* former=temp; 
	while(temp->data!=22){
		former=temp;
		temp=temp->next;
	}
	t=new Node(90,former->next);
	former->next=t;
	temp = list; 
	while(temp){
		cout<<temp->data<<endl;
		temp=temp->next;
	}
	cout<<endl;
	
	//�����ײ���5 
	temp=list;
	t=new Node(5,list);
	list=t; 
	temp=list;
	while(temp){
		cout<<temp->data<<endl;
		temp=temp->next;
	}
	cout<<endl;
	
	//����β����99 
	temp=list;
	while(temp->next){
		temp=temp->next;
	} 
	t=new Node(99);
	temp->next=t;
	temp=list;
	while(temp){
		cout<<temp->data<<endl;
		temp=temp->next;
	}
	cout<<endl;
	
	//ɾ��55 
	temp=list;
	former=temp;
	while(temp->data!=55){
		former=temp;
		temp=temp->next;
	}
	t=temp;
	former->next=temp->next;
	delete t;
	temp=list;
	while(temp){
		cout<<temp->data<<endl;
		temp=temp->next;
	}
	cout<<endl;
	
	//�������� 
	/*
	temp=list;
	list=temp->next;
	temp->next=NULL;
	Node* h;
	while(list->next){
		h=t;
		t=list->next;
		list->next=temp;
		temp=list;
		list=t;
	}
	list->next=h;
	*/
	temp=list;
	list=NULL;
	while(temp){
		t=temp;
		temp=temp->next;
		t->next=list;
		list=t; 
	}
	
	temp=list;
	for(int i=0;i<13;i++){
		cout<<temp->data<<endl;
		temp=temp->next;
	}
	cout<<endl;
	
	
	//��С������������ 
	temp=list;
	Node* m;
	ElementType b;
	while(t){
		temp=list;
		while(temp->next){
			if(temp->data>temp->next->data){
				b=temp->data;
				temp->data=temp->next->data;
				temp->next->data=b;
			}
			temp=temp->next;
		} 
		t=t->next; 
	}
	
	
	temp=list;
	for(int i=0;i<13;i++){
		cout<<temp->data<<endl;
		temp=temp->next;
	}
	cout<<endl;
	
	return 0;
}

#include <iostream>
#include "Node.cpp"
using namespace std;

int main() {
	ElementType a[10]={56,34,3,67,89,55,22,43,12,9};
	Node* list=new Node(a[0]);
	Node* end=list;
	for(int i=1;i<10;i++){
		end->next=new Node(a[i]);
		end=end->next;
	} 
	
	Node* temp = list; 
	for(int i=0;i<10;i++){
		cout<<temp->data<<endl;
		temp=temp->next;
	}
	cout<<endl;
	
	temp=list;
	while(temp->data!=89){
		temp=temp->next;
	}
	Node* t=new Node(72,temp->next);
	temp->next=t;
	temp = list; 
	for(int i=0;i<11;i++){
		cout<<temp->data<<endl;
		temp=temp->next;
	}
	cout<<endl;
	
	temp=list;
	Node* former=temp; 
	while(temp->data!=22){
		former=temp;
		temp=temp->next;
	}
	t=new Node(90,former->next);
	former->next=t;
	temp = list; 
	for(int i=0;i<12;i++){
		cout<<temp->data<<endl;
		temp=temp->next;
	}
	cout<<endl;
	
	temp=list;
	t=new Node(5,list);
	list=t; 
	temp=list;
	for(int i=0;i<13;i++){
		cout<<temp->data<<endl;
		temp=temp->next;
	}
	cout<<endl;
	
	temp=list;
	while(temp->next){
		temp=temp->next;
	} 
	t=new Node(99);
	temp->next=t;
	temp=list;
	for(int i=0;i<14;i++){
		cout<<temp->data<<endl;
		temp=temp->next;
	}
	cout<<endl;
	
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
	for(int i=0;i<13;i++){
		cout<<temp->data<<endl;
		temp=temp->next;
	}
	cout<<endl;
	
	temp=list;
	
	t=temp->next;
	temp->next=NULL;
	Node* h=t; 
	while(h!=NULL){
		h=t->next;
		t->next=temp;
	} 
	h=t->next;
	t->next=temp;
	
	temp=list;
	for(int i=0;i<13;i++){
		cout<<temp->data<<endl;
		temp=temp->next;
	}
	cout<<endl;
	
	return 0;
}

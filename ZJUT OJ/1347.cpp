//#include<bits/stdc++.h>
//using namespace std;
//
///*
//ʱ�����ƣ�2���ڴ����ƣ�65536 KB
//������������δ���ֵ��������У���һ�����ص���֯������ʱ�չ���֣�TSAB����
//���꣬ɳ�ʾ������侫Ӣ������ѡ��һ���ܳ��ĳ�Ա����ѡ���˽������衰���ơ���
//ͶƱ��TSAB�յ�n����ЧƱ��
//ÿ��Ʊ�϶���һ������ai����ʾ��ѡ�˵�ID��
//����������ĺ�ѡ�˽���ѡΪ�����Ƶ�������
//������������������ϵĺ�ѡ������ͬ������������û���˻�Ӯ��
//���д�������TSABȷ��˭����Ϊ��aces of aces����
//����
//�ж����������
//����ĵ�һ�а���һ������t����ʾ����������������
//����ÿ������������
//��һ�а���һ������n��1<=n<=1000����
//��һ�а���n������ai��1<=ai<=1000����              
//����
//����ÿ�������������������á�aces of aces�������ĺ�ѡ�˵�ID��
//���û����Ӯ��ѡ�٣��������nobody����û�����ţ�
//*/
//int main(){
//	int t, n, ai, id[1000], max=0;
//	cin>>t;
//	for(int i=0;i<t;i++){
//		max=0;
//		for(int j=0;j<1000;j++){
//			id[j]=0;
//		}
//		cin>>n;
//		for(int j=0;j<n;j++){
//			cin>>ai;
//			id[ai]++;
//		}
//		for(int j=1;j<999;j++){
//			if(id[j]>=id[max]){
//				max=j;
//			}
//		}
//		int sum=0;
//		for(int j=0;j<999;j++){
//			if(id[j]==id[max]){
//				sum++;
//			}
//		}
//		if(sum==1){
//			cout<<max<<endl;
//		} else {
//			cout<<"Nobody"<<endl;
//		}
//	}
//	return 0;
//} 



#include<iostream>
using namespace std;

int gcd(int a, int b){
	if(a>b)
		return gcd(a-b, b);
	else if(a<b)
		return gcd(a, b-a);
	else
		return a;
}


int main(){
	int n, a, b;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		cout<<"Case "<<i+1<<": "<<gcd(a,b)<<endl;
	}
} 

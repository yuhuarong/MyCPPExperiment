//#include<bits/stdc++.h>
//using namespace std;
//
///*
//时间限制：2秒内存限制：65536 KB
//在我们人类尚未发现的深宇宙中，有一个神秘的组织，叫做时空管理局（TSAB）。
//今年，沙皇决定从其精英部队中选出一名杰出的成员。当选的人将被授予“王牌”。
//投票后，TSAB收到n张有效票。
//每张票上都有一个数字ai，表示候选人的ID。
//获得提名最多的候选人将被选为“王牌得主”。
//如果有两个或两个以上的候选人有相同数量的提名，没有人会赢。
//请编写程序帮助TSAB确定谁将成为“aces of aces”。
//输入
//有多个测试用例
//输入的第一行包含一个整数t，表示测试用例的数量。
//对于每个测试用例：
//第一行包含一个整数n（1<=n<=1000）。
//下一行包含n个整数ai（1<=ai<=1000）。              
//产量
//对于每个测试用例，输出将获得“aces of aces”荣誉的候选人的ID。
//如果没有人赢得选举，则输出“nobody”（没有引号）
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

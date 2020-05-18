#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b) {
	if(a>b)
		return gcd(b,a);
	if(a==0)
		return b;
	return gcd(b%a,a);
}
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int *a=new int[n];
		queue <int >q;
		for(int i=0;i<n;i++) {
			cin>>a[i];
			q.push(a[i]);
		}
		int list[51][51];
		int k=-1;
		int prim[]={47,43,41,37,31,29,23,19,17,13,7,5,3,2};
		while(!q.empty()) {
			int m=0;
			list[++k][m++]=q.front();
			q.pop();
			for(int t=0;t<m;t++) {
				int siz=q.size();
				int run=0;
				while(!q.empty()&&run<siz) {
					int temp=q.front();
					q.pop();
					if(gcd(list[k][t],temp)==1) {
						list[k][m++]=temp;                             
					}
					else {
					q.push(temp);  
					}
				run++;
				}
			}
			list[k][m]=0;
		}
		if(k==0) {
			cout<<"0\n";
			for(int i=0;i<n;i++)
				cout<<a[i]<<" ";
		}
		else {
			int flag=1;
			for(int i=0;i<n;i++)
				if(a[i]!=47) {
					flag=0;
					break;
			}
			if(flag==0)
			cout<<"1\n47 ";
			else
			cout<<"1\n43 ";
			for(int i=1;i<n;i++)
				cout<<a[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

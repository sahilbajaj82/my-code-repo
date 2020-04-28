#include<bits/stdc++.h>
using namespace std;
void dfs(int i,int *status,int a[1000][2001]) {
	for(int k=1;k<=a[i][0];k++) {
		if(status[a[i][k]]==0) {
		//	cout<<a[i][k]<<" ";
			status[a[i][k]]=1;
			dfs(a[i][k],status,a);
		}
	}
}
	
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int a[1000][1000];
		int ak[1000][2001];
		memset(a,0,sizeof(int));
		for(int i=0;i<n;i++)
			ak[i][0]=0;
		int s=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++) {
				cin>>a[i][j];
				s+=a[i][j];
				if(a[i][j]) {
					ak[i][++ak[i][0]]=j,ak[j][++ak[j][0]]=i;
				}
			}
		/*	for(int i=0;i<n;i++) {
			for(int j=0;j<=ak[i][0];j++)
				cout<<ak[i][j]<<" ";
			cout<<endl;
		} */

		int sum=0;
		for(int i=0;i<n;i++) {
			int status[1000];
			for(int j=0;j<n;j++)
				status[j]=0;
			dfs(i,status,ak);
		//	cout<<endl;
			//cout<<"status : ";
			//for(int j=0;j<n;j++) 
			//	cout<<status[j]<<" ";
			//cout<<endl;
			for(int j=0;j<n;j++) {
				if(i!=j)
				if(status[j]==1&&a[i][j]==0)
					sum++;//,cout<<i<<" "<<j<<endl;
			}
			//cout<<"sum  "<<sum<<endl;
		}
		cout<<sum<<endl;
		
	}
	return 0;
}

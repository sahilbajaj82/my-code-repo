#include<bits/stdc++.h>
using namespace std;
int abs(int a) {
	if(a<0)
		return -1*a;
	return a;
}
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n,m;
		cin>>n>>m;
		int con=m+n+2;
		const int size=1602;
		int a[size][size];
		memset(a, 0, sizeof(a[0][0]) * size * size);
		for(int i=0;i<n;i++) {
			char c[302];
			cin>>c;
			for(int j=0;j<m;j++)
				a[con+i][con+j]=c[j]-'0';
		}
		int arr[802];
		for(int i=0;i<802;i++)
			arr[i]=0;
		int di1[size][size];
		int di2[size][size];
		
		memset(di1, 0, sizeof(di1[0][0]) * size * size);
		memset(di2, 0, sizeof(di2[0][0]) * size * size);
		
		for(int i=0;i<n+2*con;i++) {
			for(int j=0;j<m+2*con;j++) {
					di1[i+1][j+1]=di1[i][j+2]+a[i][j];
					di2[i+1][j+1]=di2[i][j]+a[i][j];
			}
		}
		/*
		for(int i=0;i<=n+1+2*con;i++) {
			for(int j=0;j<=m+1+2*con;j++)
				cout<<di1[i][j]<<" ";
			cout<<endl;
		}
		cout<<"\n\n";
		for(int i=0;i<=n+1+2*con;i++) {
			for(int j=0;j<=m+1+2*con;j++)
				cout<<di2[i][j]<<" ";
			cout<<endl;
		}
		cout<<"\n"; */
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++){
				if(a[i+con][j+con]) {
					for(int d=1;d<m+n-1;d++) {
						arr[d]=arr[d]+di1[con+i+d+1][con+j+1]-di1[con+i][con+j+1+d+1];
						arr[d]=arr[d]+di1[con+i+1][con+j+1-d]-di1[con+i+1-d-1][con+j+1+1];
						arr[d]=arr[d]+di2[con+i+1][con+j+d+1]-di2[con+i+1-d-1][con+j];
						arr[d]=arr[d]+di2[con+i+1+d][con+j+1]-di2[con+i][con+j+1-1-d];
						if(i-d>=0)
						arr[d]-=a[con+i-d][con+j];
						if(j-d>=0)
						arr[d]-=a[i+con][con+j-d];
						if(i+d<n)
						arr[d]-=a[con+i+d][j+con];
						if(j+d<m)
						arr[d]-=a[i+con][j+con+d];
					
					
					//cout<<i<<" "<<j<<" "<<d<<" "<<arr[d]<<endl;
					}
				}
			}
	   }
		for(int i=1;i<n+m-1;i++){
			cout<<arr[i]/2<<" ";
		}
		cout<<endl;
		
		
		
	}
}

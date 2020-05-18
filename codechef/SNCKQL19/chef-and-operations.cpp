#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int *a=new int[n];
		int *b=new int[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		int flag=1;
		for(int i=0;i<n;i++){
			cin>>b[i]; 
			b[i]=b[i]-a[i];
			if(b[i]<0)
				flag=0;
		}
		for(int i=0;i<n-2;i++) {
			if(b[i]>0) {
				b[i+2]=b[i+2]-3*b[i];
				b[i+1]=b[i+1]-2*b[i];
				b[i]=0;
			}
			if(b[i]<0) {
				flag=0;
				break;
			}
		}
		if(b[n-2]!=0)
			flag=0;
		if(b[n-1]!=0)
			flag=0;
		if(flag)
			cout<<"TAK\n";
		else
			cout<<"NIE\n";
	}
	return 0;
}


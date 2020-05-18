#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int *a=new int[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		int flag=1;
		int i,k;
		int check=0;
		for(i=1;i<n;i++) {
			if(a[i]<a[i-1]) {
				check=1;
				break;
			}
		}
		k=i;
		for(i=i+1;i<n;i++) {
			if(a[i]<a[i-1]) {
				flag=0;
				break;
			}
		}
		if(a[n-1]>a[0]&&check)
			flag=0;
		if(flag)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}

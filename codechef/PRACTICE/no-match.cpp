#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int a[n+1];
		for(int i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		long sum=0;
		for(int i=0;i<n/2;i++) {
			sum=sum+a[n-i-1]-a[i];
		}
		cout<<sum<<endl;
	}
	return 0;
}

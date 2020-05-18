#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n,k;
		cin>>n>>k;
		int *a=new int[n];
		for(int i=0;i<n;i++) {
			cin>>a[i];
		}
		sort(a,a+n);
		int bar=a[n-k];
		int count=0;
		for(int i=0;i<n;i++) {
			if(bar<=a[i])
				count++;
		}
		cout<<count<<endl;
	}
	return 0;
}

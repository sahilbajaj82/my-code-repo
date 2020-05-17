#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	int t;
	cin>>t;
	while(t--) {
		long n,m,k;
		cin>>n>>m>>k;
		int *a=new int[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		int flag=1;
		for(int i=0;i<n-1;i++) {
			if(a[i+1]-k>=a[i]) {
				m=m-((a[i+1]-k)-a[i]);
				if(m<0) {
					flag=0;
					break;
				}
			}
			else {
				int g=a[i]-(a[i+1]-k);
				if(a[i]-g<0)
					g=a[i];
				m=m+g;
			}
		//	cout<<m<<endl;

		}
		if(flag) {
			cout<<"YES\n";
		}
		else {
			cout<<"NO\n";
		}
	}
	return 0;
}
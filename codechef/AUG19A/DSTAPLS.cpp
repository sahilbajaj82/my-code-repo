#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	int t;
	cin>>t;
	while(t--) {
		ll n,k;
		cin>>n>>k;
		if(k==1)
			cout<<"NO";
		else if(n==k)
			cout<<"YES";
		else {
			n=n/k;
			if(n%(k)==0)
				cout<<"NO";
			else
				cout<<"YES";
		}
		cout<<"\n";
	}
	return 0;
}
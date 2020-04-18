#include<bits/stdc++.h>
#define ll long 
using namespace std;
int main() {
	ll t;cin>>t;
	while(t--) {
		ll n;cin>>n;
		ll c[n],h[n];
		ll dr[n],pod[n];
		int i=0;
		for(i=0;i<n;i++)
			cin>>c[i];
		for(i=0;i<n;i++) {
			cin>>h[i];
			dr[i]=0,pod[i]=0;
		}
		sort(h,h+n);
		i=0;
		while(i<n) {
			int l=i-c[i];int r=i+c[i];
			if(r<n) {
				dr[r+1]--;
			}
			if(l<0) {
				dr[0]++;
			}
			else {
				dr[l]++;
			}
			i++;
		}
		pod[0]=dr[0];
		for(i=1;i<n;i++){
			pod[i]=pod[i-1]+dr[i];dr[i]=0;
		}
		sort(pod,pod+n);
		int flag=1;
		i=0;
		while(i<n) {
			if(pod[i]!=h[i]) {
				flag=0;
				break;
			}
			i++;
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
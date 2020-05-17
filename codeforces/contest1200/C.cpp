#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a, ll b) { 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 
int main() {
	ll n,m;
	cin>>n>>m;
	int q;
	cin>>q;
	ll div=gcd(n,m);
	ll gh[2];
	gh[0]=n/div;
	gh[1]=m/div;
	//cout<<div<<endl;
	while(q--) {
		ll s1,s2,e1,e2;
		cin>>s1>>s2>>e1>>e2;
		ll x1=(s2-1)/gh[s1-1];
		ll x2=(e2-1)/gh[e1-1];
		if(x1==x2)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}
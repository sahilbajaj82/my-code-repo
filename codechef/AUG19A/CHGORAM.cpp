#include<bits/stdc++.h>
#define ll long long
using namespace std;
void addEdge(vector<ll> adj[], ll u, ll v) { 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 
bool findPath(vector<ll> v[], ll first, ll end,vector<bool> &discovered,vector<ll> &path) {
	discovered[first] = true;
	path.push_back(first);
	if (first==end)
		return true;
	for (ll i:v[first])
		if (!discovered[i])
			if (findPath(v,i,end,discovered,path))
				return true;
	path.pop_back();
	return false;
}
int main() {
	ll t;
	cin>>t;
	while(t--) {
		ll n;
		cin>>n;
		if(n<1005) {
		ll p1,p2,p3;
		cin>>p1>>p2>>p3;
		ll a[n+1];
		vector <ll> v[n+1];
		for(ll i=0;i<=n;i++)
			a[i]=0;
		for(ll i=0;i<n-1;i++) {
			ll x,y;
			cin>>x>>y;
			addEdge(v,x,y);
			a[x]++;
			a[y]++;
		}
		ll count=0;
		for(ll i=1;i<=n;i++) {
			for(ll j=1;j<=n;j++) {
				if(i==j)
					continue;
				std::vector<bool > discovered(n+1);
				std::vector<ll> path;
				if(findPath(v,i,j,discovered,path)) {
					for(ll k:path) {
						if(k==i||k==j){
							continue;
						}
						if(p1<p2&&p2<p3&&i<k&&k<j)
							count++;
						else if(p2<p1&&p1<p3&&k<i&&i<j)
							count++;
						else if(p1<p3&&p3<p2&&i<j&&j<k)
							count++;
						else if(p2<p3&&p3<p1&&k<j&&j<i)
							count++;
						else if(p3<p1&&p1<p2&&j<i&&i<k)
							count++;
						else if(p3<p2&&p2<p1&&j<k&&k<i)
							count++;
					}
				}
				
			}
		}
		cout<<count<<endl;
		}
		else {
			ll p1,p2,p3;
		cin>>p1>>p2>>p3;
		ll a[n+1];
		vector <ll> v[n+1];
		for(ll i=0;i<=n;i++)
			a[i]=0;
		for(ll i=0;i<n-1;i++) {
			ll x,y;
			cin>>x>>y;
			addEdge(v,x,y);
			a[x]++;
			a[y]++;
		}
		ll count=0;
		int check=1;
		for(int i=1;i<=n;i++) {
			if(a[i]>2)
				check=0;
		}
		if(check==0) { //star graph
			ll max=1;
			for(ll i=2;i<=n;i++) {
				if(a[max]<a[i])
					max=i;
			}
			if(p2==1) {
				ll pol=n-max;
				count=(pol*(pol-1))/2;
			}
			else if(p2==2) {
				ll l=max-1;
				ll r=n-max;
				count=r*l;
			}
			else {
				ll pol=max-1;
				count=(pol*(pol-1))/2;
			}
		}
		else { //path graph
			int j=1;
			for(int i=1;i<=n;i++)
				if(a[i]==1) {
					j=i;
					break;
				}
			int b[n+1];
			b[0]=j;
			int prev=-1;
			for(int i=1;i<n;i++) {
				for(auto x: v[j]) {
					if(x==prev)
						continue;
					b[i]=x;
					prev=j;
					j=x;
				}
			}
			
		}
		cout<<count<<endl;
		}
	}
	return 0;
}
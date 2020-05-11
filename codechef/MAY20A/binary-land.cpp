#include <bits/stdc++.h>   
using namespace std;   
using ll =long long;
#define F first
#define S second
#define pb push_back
ll M =1000000007;
string a[30001];
ll in=0;
ll last=0;
int n;
ll b[30001][21];
ll findpath(ll x,ll y,ll fr,char c) {
	// cout<<x<<" "<<y<<" "<<fr<<endl;
	if(x<=0&&x>n) {
		return 0;
	}
	if(fr>=in) {
		return 0;
	}
	if((x==y)&&(fr==in-1)&&a[fr][x-1]==c) {
		return 1;
	}
	if(b[fr][x-1]!=-1) {
		return b[fr][x-1];
	}
	ll c1=0;
	if(a[fr][x-1]==c)
		c1=(findpath(x+1,y,fr+1,c)+findpath(x-1,y,fr+1,c)+findpath(x,y,fr+1,c))%M;
	b[fr][x-1]=c1;
	return c1; 
}
int main() {   
    ios::sync_with_stdio(0);   
    cin.tie(0);   
    cout.tie(0);
    #ifndef ONLINE_JUDGE   
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout);
    #endif   
    int q;
    cin>>n>>q;
    while(q--) {
    	string s;
    	cin>>s;
    	if(s=="add") {
    		string s2;
    		cin>>s2;
    		a[in]=s2;
    		in++;
    	}
    	else if(s=="remove") {
    		last++;
    	}
    	else {
    		for(ll i=last;i<in;i++) {
    			for(ll j=0;j<=n;j++) {
    				b[i][j]=-1;
    			}
    		}
    		ll x,y;
    		cin>>x>>y;
    		cout<<findpath(x,y,last,a[last][x-1])<<endl;
    	}
    }
    return 0;  
}   
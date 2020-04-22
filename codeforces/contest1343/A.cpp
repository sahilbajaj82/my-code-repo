#include <bits/stdc++.h>   
using namespace std;   
using ll =long long;
#define F first
#define S second
#define pb push_back
int main() {   
    ios::sync_with_stdio(0);   
    cin.tie(0);   
    cout.tie(0);
    #ifndef ONLINE_JUDGE   
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout);
    #endif   
    int t;
    cin>>t;
    while (t--) {   
        long long n;
        cin>>n;
        ll ans;
        ll x=2;
        while(x<n) {
        	if(n%(x*2-1)==0) {
        		ans=n/(x*2-1);
        	}
        	x=x*2;
        }
        cout<<ans<<endl;
    }   
    return 0;  
}   